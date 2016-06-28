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
    /// Provides PWM functionality.
    /// </summary>
    /// <remarks>
    /// Please refer to your platform documentation for the available PWM pins.<br/>
    /// <br/>
    /// </remarks>
    public class PWM : IDisposable
    {
        /// <summary>
        /// Lists the PWM pins.
        /// </summary>
        public enum Pin : byte
        {
            /// <summary>PWM pin.</summary>
            PWM0,
            /// <summary>PWM pin.</summary>
            PWM1,
            /// <summary>PWM pin.</summary>
            PWM2,
            /// <summary>PWM pin.</summary>
            PWM3,
            /// <summary>PWM pin.</summary>
            PWM4,
            /// <summary>PWM pin.</summary>
            PWM5,
            /// <summary>PWM pin.</summary>
            PWM6,
            /// <summary>PWM pin.</summary>
            PWM7,
            /// <summary>PWM pin.</summary>
            PWM8,
            /// <summary>PWM pin.</summary>
            PWM9,
            /// <summary>PWM pin.</summary>
            PWM10,
            /// <summary>PWM pin.</summary>
            PWM11,
            /// <summary>PWM pin.</summary>
            PWM12,
            /// <summary>PWM pin.</summary>
            PWM13,
            /// <summary>PWM pin.</summary>
            PWM14,
            /// <summary>PWM pin.</summary>
            PWM15,
        }

#pragma warning disable 0169, 0414
        private byte disposed;
        private byte channel;
#pragma warning restore 0169, 0414

        /// <summary>
        /// Disposes the pin and marks it as available again.
        /// </summary>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public void Dispose();

        /// <exclude/>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern ~PWM();

        /// <summary>
        /// Creates a new PWM pin.
        /// </summary>
        /// <param name="pin">Needed pin.</param>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public PWM(PWM.Pin pin);

        /// <summary>
        /// Sets the PWM's frequency and duty cycle.
        /// </summary>
        /// <param name="freq_Hz">Required frequency in Hertz.</param>
        /// <param name="dutyCycle">Duty cycle percentage. 0 to 100 inclusive.</param>
        /// <remarks>
        /// Setting the frequency to 0 would stop the PWM.<br/>
        /// 0% and 100% are valid values for the duty cycle.
        /// </remarks>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public void Set(int freq_Hz, byte dutyCycle);

        /// <summary>
        /// Sets the PWM pin as high or low.
        /// </summary>
        /// <param name="pinState"><c>true</c> if high.</param>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public void Set(bool pinState);

        /// <summary>
        /// Sets the PWM using the period time and high time.
        /// </summary>
        /// <param name="period_nanosecond">Period of the signal in nano seconds.</param>
        /// <param name="highTime_nanosecond">High time of the signal in nano seconds.</param>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern public void SetPulse(uint period_nanosecond, uint highTime_nanosecond);
    }
}
