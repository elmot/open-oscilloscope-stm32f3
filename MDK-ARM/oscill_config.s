	AREA    MyBinFile1_Section, DATA, READONLY
	EXPORT OscillConfigData
OscillConfigData
    DCD OscillConfigDataExt_End - OscillConfigDataExt
OscillConfigDataExt
	INCBIN ../Src/exampleConfig.txt
OscillConfigDataExt_End		
	END