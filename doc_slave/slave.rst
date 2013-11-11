I2S Slave
'''''''''

This module is an I2S slave transmitter and receiver in a single thread. It sends and receives samples over a pair of chanends and transmits audio over I2S. It can send and receive multiple I2S links on separate ports.

As a slave it is driven by the bit clock (BCK) and word clock (WCK) on input ports.

module_i2s_slave
----------------

This module is a single thread I2S bus slave. It can transmit and receive audio data from an external word clock and bit clock.

It requires the following resources:

   - 1 thread (MIPS dependant on number of inputs and outputs)

   - 1 clock block

   - 1 x 1-bit input port for each I2S input plus 2 for BCK and WCK

   - 1 x 1-bit output port for each I2S output

   - 0.5 kB memory

Hardware Requirements
---------------------

This module can be used with any audio CODEC that supports the I2S standard. 

Component Description
---------------------



API
===

Symbolic constants
------------------

.. doxygendefine:: I2S_SLAVE_NUM_IN

.. doxygendefine:: I2S_SLAVE_NUM_OUT

Structures
----------

.. doxygenstruct:: i2s_slave

Functions
---------

.. doxygenfunction:: i2s_slave

Example
=======

This example is designed to run on the XR-USB-AUDIO-2.0-MC board. It takes input on 3 I2S links and outputs the selected one on four I2S links. I2S_SLAVE_NUM_IN and I2S_SLAVE_NUM_OUT are defined in the Makefile.

First of all i2s_slave should be included and the structure i2s_slave defined.

.. literalinclude:: app_xai_i2s_slave_demo/src/main.xc
  :start-after: //::declaration
  :end-before: //::

The top level of this example creates the i2s_slave on core 1, along with a 1KHz clock to the PLL and occupies the remaining 6 threads with computation.

Core 0 runs the loopback function which reads the I2S inputs from the i2s_slave thread over a streaming channel and sends them over a streaming channel back to the i2s_slave thread to the I2S outputs.

.. literalinclude:: app_xai_i2s_slave_demo/src/main.xc
  :start-after: //::main program
  :end-before: //::
