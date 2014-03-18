////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;
using Microsoft.SPOT.Hardware;

namespace GHI.OSHW.Hardware
{
    /// <summary>
    /// Utilities.
    /// </summary>
    public static class Util
    {
        /// <summary>
        /// Bits per pixel conversion type.
        /// </summary>
        public enum BPP_Type : byte
        {
            /// <summary>
            /// 1 BPP for displays of 128 width and 128 or 64 height. The 1-bit pixel is set if the bitmap pixel has any color besides black.
            /// </summary>
            BPP1_x128,
            /// <summary>
            /// 8 BPP with RGB 3:3:2.
            /// </summary>
            BPP8_RGB,//3:3:2
            /// <summary>
            /// 8 BPP from red channel.
            /// </summary>
            BPP8_RED,
            /// <summary>
            /// 8 BPP from green channel.
            /// </summary>
            BPP8_GREEN,
            /// <summary>
            /// 8 BPP from blue channel.
            /// </summary>
            BPP8_BLUE,
            /// <summary>
            /// Big Endian 16 BPP with RGB 5:6:5. 
            /// </summary>
            BPP16_RGB_BE,//5:6:5
            /// <summary>
            /// Little Endian 16 BPP with RGB 5:6:5. 
            /// </summary>
            BPP16_RGB_LE,
            /// <summary>
            /// Big Endian 16 BPP with BGR 5:6:5. 
            /// </summary>
            BPP16_BGR_BE,
            /// <summary>
            /// Little Endian 16 BPP with BGR 5:6:5. 
            /// </summary>
            BPP16_BGR_LE,
        }

        /// <summary>
        /// Converts <c>Bitmap</c> pixel bytes into different BPP representation.
        /// </summary>
        /// <param name="bitmapBuffer">Bitmap bytes.</param>
        /// <param name="outputBuffer">Output buffer after conversion.</param>
        /// <param name="bpp">Target bits per pixel representation.</param>
        /// <remarks>
        /// GHI Electronics' devices support Bitmap and WPF graphics natively on color TFT displays. A design may require a small low-cost SPI-based displays. Different SPI LCDs can have different BPP requirements. This function converts the Bitmap bytes, where each pixel is represented as 4 bytes, into the needed BPP representation and then it can be transferred to the display.<br/>
        /// Start by doing all necessary graphics in NETMF on a Bitmap object. When you need to flush the results to the LCD:<br/>
        /// 1) Get the Bitmap bytes using <c>myBitmap.GetBitmap()</c>.<br/>
        /// 2) Use this conversion method to convert the buffer into the needed BPP.<br/>
        /// 3) Send output buffer to LCD over SPI.<br/>
        /// <br/>
        /// This drawing technique can be used also with Windows Presentation Foundation but it does not work on old non-TFT Embedded Master and it requires the following:<br/>
        /// 1) Set the display size to match your SPI-display using SetLCD. Use any values for timing and 0xFF for <c>PixelClockDivider</c> which will disable TFT LCD refresh.<br/>
        /// 2) Use the following code to fetch the Bitmap object from the WPF system.
        /// <code>
        /// WindowManager.Instance.PostRender += new PostRenderEventHandler(Instance_PostRender);
        /// // …
        /// void Instance_PostRender(DrawingContext dc)
        /// {
        ///    // get bitmap bytes
        ///    byte[] MyBitmapBytes = dc.Bitmap.GetBitmap();
        /// 
        ///    // do any necessary conversion
        ///    Util.ConvertBPP(MyBitmapBytes, output, Util.BPP_Type.BPP16_RGB_LE);
        /// 
        ///    // send over SPI
        ///    MySPIDisplay.FlushData(output);
        /// }
        /// </code>
        /// </remarks>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public static void BitmapConvertBPP(byte[] bitmapBuffer, byte[] outputBuffer, BPP_Type bpp);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern private static bool SetSpecialDisplayConfig(int key, int value);

		/// <summary>
		/// Sets special configuration values in the firmware for display support on certain mainboards.
		/// </summary>
		/// <param name="spiConfig">The spi configuration used to communicate with the device.</param>
		/// <param name="bpp">The BPP format the device expects.</param>
		/// <param name="orientation">The orientation of the screen. 0 = 0 degrees, 1 = 90 degrees, 2 = 180 degrees, 3 = 270 degrees, all clockwise.</param>
		/// <param name="rsPin">The register select pin, if present, to use.</param>
		/// <returns>Whether or not the configuration was set.</returns>
		public static bool SetSpecialDisplayConfig(SPI.Configuration spiConfig, BPP_Type bpp, int orientation = -1, Cpu.Pin rsPin = Cpu.Pin.GPIO_NONE)
		{
			var failureCount = 0;

			failureCount += Util.SetSpecialDisplayConfig(1, spiConfig != null ? 1 : 2) ? 0 : 1;
			failureCount += Util.SetSpecialDisplayConfig(2, (int)bpp) ? 0 : 1;

			if (orientation != -1)
				failureCount += Util.SetSpecialDisplayConfig(3, (int)orientation) ? 0 : 1;

			if (rsPin != Cpu.Pin.GPIO_NONE)
				failureCount += Util.SetSpecialDisplayConfig(4, (int)rsPin) ? 0 : 1;

			if (spiConfig != null)
			{
				failureCount += Util.SetSpecialDisplayConfig(5, (int)spiConfig.ChipSelect_Port) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(6, spiConfig.ChipSelect_ActiveState ? 1 : 0) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(7, spiConfig.Clock_IdleState ? 1 : 0) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(8, spiConfig.Clock_Edge ? 1 : 0) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(9, (int)spiConfig.Clock_RateKHz) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(10, (int)spiConfig.ChipSelect_SetupTime) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(11, (int)spiConfig.ChipSelect_HoldTime) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(12, (int)spiConfig.SPI_mod) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(13, (int)spiConfig.BusyPin) ? 0 : 1;
				failureCount += Util.SetSpecialDisplayConfig(14, spiConfig.BusyPin_ActiveState ? 1 : 0) ? 0 : 1;
			}

			return failureCount == 0;
		}

        /// <summary>
        /// Allows .wav file playback through AnalogOut
        /// </summary>
        /// <param name="channel">AnalogOut Channel</param>
        /// <param name="data">.wav file buffer</param>
        /// <param name="offset">Array offset</param>
        /// <param name="count">Size of playback sample</param>
        /// <param name="dataRate">Frequency in Hz</param>
        public static void PlayPCMAudio(Cpu.AnalogOutputChannel channel, byte[] data, int offset, int count, int dataRate)
        {
            if (DeviceInfo.GetDeviceID() == DeviceID.FEZ_CERB)
                PlayPCMAudio((byte)channel, data, offset, count, dataRate);
            else
            {
                throw new NotSupportedException();
            }
            
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern private static void PlayPCMAudio(byte channel, byte[] data, int offset, int count, int dataRate);

    }
}
