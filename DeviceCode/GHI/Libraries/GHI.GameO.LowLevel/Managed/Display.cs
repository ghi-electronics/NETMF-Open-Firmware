using System;
using System.Runtime.CompilerServices;

namespace GHI.GameO.LowLevel
{
	/// <summary>
	/// Provides low-level access to the display on the Game-O.
	/// </summary>
	public static class Display
	{
		/// <summary>
		/// Initializes the display.
		/// </summary>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void Initialize();

		/// <summary>
		/// Sends a ushort to the display.
		/// </summary>
		/// <param name="data">The ushort to send.</param>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void WriteRaw(ushort data);

		/// <summary>
		/// Sends raw data to the display.
		/// </summary>
		/// <param name="data">The data to write.</param>
		/// <param name="offset">The offset to begin sending from.</param>
		/// <param name="count">The amount to send.</param>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void WriteRaw(byte[] data, int offset, int count);

		/// <summary>
		/// Sends raw data to the display.
		/// </summary>
		/// <param name="data">The data to write.</param>
		/// <param name="offset">The offset to begin sending from.</param>
		/// <param name="count">The amount to send.</param>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void WriteRaw(ushort[] data, int offset, int count);

		/// <summary>
		/// Selects the register in the driver.
		/// </summary>
		/// <param name="register">The register to select.</param>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void SetRegister(ushort register);

		/// <summary>
		/// Writes to a register.
		/// </summary>
		/// <param name="register">The register to write to.</param>
		/// <param name="value">The value to write.</param>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void WriteRegister(ushort register, ushort value);

		/// <summary>
		/// Sets the drawing window for the next write.
		/// </summary>
		/// <param name="x">The x coordinate.</param>
		/// <param name="y">The y coordinate.</param>
		/// <param name="width">The width.</param>
		/// <param name="height">The height.</param>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void SetDrawWindow(ushort x, ushort y, ushort width, ushort height);
	  
		/// <summary>
		/// Draws an image on the display.
		/// </summary>
		/// <param name="image">The image data. Expected to be in BPP16_BGR_LE format.</param>
		/// <param name="xDst">The x coordinate on the screen to begin drawing at.</param>
		/// <param name="yDst">The y coordinate on the screen to begin drawing at.</param>
		/// <param name="xSrc">The x coordinate to begin drawing from in the image sent.</param>
		/// <param name="ySrc">The y coordinate to begin drawing from in the image sent.</param>
		/// <param name="imageWidth">The width of the image.</param>
		/// <param name="imageHeight">The height of the image.</param>
		/// <param name="drawWidth">The width of the image to draw on the display.</param>
		/// <param name="drawHeight">The height of the image to draw on the display.</param>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void DrawImage(byte[] image, ushort xDst, ushort yDst, ushort xSrc, ushort ySrc, ushort imageWidth, ushort imageHeight, ushort drawWidth, ushort drawHeight);

		/// <summary>
		/// Draws an image on the display.
		/// </summary>
		/// <param name="image">The image data. Expected to be in BPP16_BGR_LE format.</param>
		/// <param name="xDst">The x coordinate on the screen to begin drawing at.</param>
		/// <param name="yDst">The y coordinate on the screen to begin drawing at.</param>
		/// <param name="xSrc">The x coordinate to begin drawing from in the image sent.</param>
		/// <param name="ySrc">The y coordinate to begin drawing from in the image sent.</param>
		/// <param name="imageWidth">The width of the image.</param>
		/// <param name="imageHeight">The height of the image.</param>
		/// <param name="drawWidth">The width of the image to draw on the display.</param>
		/// <param name="drawHeight">The height of the image to draw on the display.</param>
		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		extern public static void DrawImage(ushort[] image, ushort xDst, ushort yDst, ushort xSrc, ushort ySrc, ushort imageWidth, ushort imageHeight, ushort drawWidth, ushort drawHeight);
	}
}