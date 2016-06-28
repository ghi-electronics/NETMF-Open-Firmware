using System;
using Microsoft.SPOT;
using System.Runtime.CompilerServices;
using Microsoft.SPOT.Hardware;

namespace GHIElectronics.OSH.NETMF.Native
{
    /// <summary>
    /// Runtime Loadable Procedures. 
    /// RLP allows developers to load/execute their own compiled C/Assembly procedures at runtime.
    /// </summary>
    public static class RLPLite
    {
        static RLPLite()
        {

        }

        ///////////////////////////////////////////////

        /// <summary>
        /// Native Procedure. 
        /// </summary>
        public class Procedure
        {
            uint address;

            /// <summary>
            /// Creates a native procedure from a given address.
            /// </summary>
            /// <param name="address">Procedure address.</param>
            public Procedure(uint address)
            {
                this.address = address;
            }

            /// <summary>
            /// Calls a native procedure.
            /// </summary>
            /// <param name="VoidArray">Array of type float.</param>
            /// <param name="IntArray">Array of type int.</param>
            /// <param name="ByteArray">Array of type byte.</param>            
            /// <returns>Return value.</returns>
            [MethodImpl(MethodImplOptions.Synchronized)]
            public int Invoke(float[] VoidArray, Int32[] IntArray, Byte[] ByteArray)
            {
                int ret = 0;

                ret = Invoke_Helper(VoidArray, IntArray, ByteArray);

                return ret;
            }

            [MethodImplAttribute(MethodImplOptions.InternalCall)]
            extern private int Invoke_Helper(float[] VoidArray, Int32[] IntArray, Byte[] ByteArray);

            /// <summary>
            /// Calls a native procedure.
            /// </summary>
            /// <param name="VoidArray">Array of type unsigned int.</param>
            /// <param name="IntArray">Array of type int.</param>
            /// <param name="ByteArray">Array of type byte.</param>            
            /// <returns>Return value.</returns>
            [MethodImpl(MethodImplOptions.Synchronized)]
            public int Invoke(UInt32[] VoidArray, Int32[] IntArray, Byte[] ByteArray)
            {
                int ret = 0;

                ret = Invoke_Helper(VoidArray, IntArray, ByteArray);

                return ret;
            }

            [MethodImplAttribute(MethodImplOptions.InternalCall)]
            extern private int Invoke_Helper(UInt32[] VoidArray, Int32[] IntArray, Byte[] ByteArray);

            /// <summary>
            /// Calls a native procedure.
            /// </summary>
            /// <param name="VoidArray">Array of type int.</param>
            /// <param name="IntArray">Array of type int.</param>
            /// <param name="ByteArray">Array of type byte.</param>            
            /// <returns>Return value.</returns>
            [MethodImpl(MethodImplOptions.Synchronized)]
            public int Invoke(Int32[] VoidArray, Int32[] IntArray, Byte[] ByteArray)
            {
                int ret = 0;

                ret = Invoke_Helper(VoidArray, IntArray, ByteArray);

                return ret;
            }

            [MethodImplAttribute(MethodImplOptions.InternalCall)]
            extern private int Invoke_Helper(Int32[] VoidArray, Int32[] IntArray, Byte[] ByteArray);

            /// <summary>
            /// Calls a native procedure.
            /// </summary>
            /// <param name="VoidArray">Array of type byte.</param>
            /// <param name="IntArray">Array of type int.</param>
            /// <param name="ByteArray">Array of type byte.</param>            
            /// <returns>Return value.</returns>
            [MethodImpl(MethodImplOptions.Synchronized)]
            public int Invoke(Byte[] VoidArray, Int32[] IntArray, Byte[] ByteArray)
            {
                int ret = 0;

                ret = Invoke_Helper(VoidArray, IntArray, ByteArray);

                return ret;
            }

            [MethodImplAttribute(MethodImplOptions.InternalCall)]
            extern private int Invoke_Helper(Byte[] VoidArray, Int32[] IntArray, Byte[] ByteArray);

            /// <summary>
            /// Calls a native procedure.
            /// </summary>
            /// <param name="VoidArray">Array of type signed byte.</param>
            /// <param name="IntArray">Array of type int.</param>
            /// <param name="ByteArray">Array of type byte.</param>            
            /// <returns>Return value.</returns>
            [MethodImpl(MethodImplOptions.Synchronized)]
            public int Invoke(SByte[] VoidArray, Int32[] IntArray, Byte[] ByteArray)
            {
                int ret = 0;

                ret = Invoke_Helper(VoidArray, IntArray, ByteArray);

                return ret;
            }

            [MethodImplAttribute(MethodImplOptions.InternalCall)]
            extern private int Invoke_Helper(SByte[] VoidArray, Int32[] IntArray, Byte[] ByteArray);

        }// end class Procedure
    }// end class RLPLite
}// end namespace GHIElectronics.OSH.NETMF.Native
