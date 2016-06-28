////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;

namespace GHIElectronics.OSH.NETMF.Hardware
{
    /// <summary>
    /// Provides the ability to read an analog input pin.
    /// </summary>
    /// <remarks>
    /// Please refer to your platform documentation for the available analog pins. The analog pin is initialized with the default platform resolution.<br/>
    /// <br/>
    /// </remarks>
    public class AnalogIn : IDisposable
    {
        /// <summary>
        /// Lists the analog input pins.
        /// </summary>
        public enum Pin : byte
        {
            /// <summary>Analog input pin.</summary>
            Ain0,
            /// <summary>Analog input pin.</summary>
            Ain1,
            /// <summary>Analog input pin.</summary>
            Ain2,
            /// <summary>Analog input pin.</summary>
            Ain3,
            /// <summary>Analog input pin.</summary>
            Ain4,
            /// <summary>Analog input pin.</summary>
            Ain5,
            /// <summary>Analog input pin.</summary>
            Ain6,
            /// <summary>Analog input pin.</summary>
            Ain7,
            /// <summary>Analog input pin.</summary>
            Ain8,
            /// <summary>Analog input pin.</summary>
            Ain9,
            /// <summary>Analog input pin.</summary>
            Ain10,
            /// <summary>Analog input pin.</summary>
            Ain11,
            /// <summary>Analog input pin.</summary>
            Ain12,
            /// <summary>Analog input pin.</summary>
            Ain13,
            /// <summary>Analog input pin.</summary>
            Ain14,
            /// <summary>Analog input pin.</summary>
            Ain15,
        }

#pragma warning disable 0169
        private byte channel;
        private byte disposed;
        private int min;
        private int max;
#pragma warning restore 0169

        /// <summary>
        /// Disposes the pin and marks it as available again.
        /// </summary>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public void Dispose();

        /// <exclude/>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern ~AnalogIn();

        /// <summary>
        /// Creates a new analog pin.
        /// </summary>
        /// <param name="ain">Needed analog pin.</param>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public AnalogIn(AnalogIn.Pin ain);

        /// <summary>
        /// Scales the analog value when reading automatically into a specific range.
        /// </summary>
        /// <param name="minValue">Min value.</param>
        /// <param name="maxValue">Max value.</param>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public void SetLinearScale(int minValue, int maxValue);

        /// <summary>
        /// Reads the current analog value.
        /// </summary>
        /// <returns>Current analog value.</returns>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public int Read();
    }
}
