	AREA    MyBinFile1_Section, DATA, READONLY
	EXPORT OscillConfigData
OscillConfigData
    DCD OscillConfigDataExt_End - OscillConfigDataExt
OscillConfigDataExt
	INCBIN exampleConfig.txt
OscillConfigDataExt_End		
	END