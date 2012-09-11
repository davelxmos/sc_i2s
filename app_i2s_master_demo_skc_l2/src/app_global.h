
#ifndef _APP_GLOBAL_H_
#define _APP_GLOBAL_H_

/* Core that Audio Slice is connected to */
#define AUDIO_IO_CORE 		            1

/* Audio sample frequency (Hz) */
#define SAMP_FREQ			            48000

/* Audio Slice hardware version */
#define AUDIO_SLICE_HW		            1

/* Audio clocking defines */ 
/* Master clock defines (Hz) */
#define MCLK_FREQ_441                   (512*44100)   /* 44.1, 88.2 etc */
#define MCLK_FREQ_48                    (512*48000)   /* 48, 96 etc */

#if (SAMP_FREQ%22050==0)
#define MCLK_FREQ                       MCLK_FREQ_441
#elif (SAMP_FREQ%24000==0)
#define MCLK_FREQ                       MCLK_FREQ_48
#else
#error Unsupported sample frequency
#endif

/* Bit clock divide */
//#define BCLK_DIV                        (MCLK_FREQ / (SAMP_FREQ * 64))


/* Ports */
#if (AUDIO_SLICE_HW == 1)
#define PORT_I2S_DAC0	                XS1_PORT_1D
#define PORT_I2S_DAC1                   XS1_PORT_1M
#define PORT_I2S_ADC0                   XS1_PORT_1I
#define PORT_I2S_ADC1	                XS1_PORT_1L
#define PORT_I2S_LRCLK		            XS1_PORT_1H
#define PORT_I2S_BCLK		            XS1_PORT_1A
#define PORT_MCLK_IN		            XS1_PORT_1E

#define PORT_GPIO			            XS1_PORT_4E
#define PORT_I2C			            XS1_PORT_4F
#else
#error currently not un-supported slice hw version
#endif

#endif /* ifndef _GLOBAL_H_ */

