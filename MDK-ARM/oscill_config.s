	AREA    MyBinFile1_Section, DATA, READONLY
	EXPORT OscillConfigData
OscillConfigData
    DCD OscillConfigDataExt_End - OscillConfigDataExt
OscillConfigDataExt
	INCBIN ../oscill-gui/src/main/resources/xyz/elmot/oscill/exampleConfig.json
OscillConfigDataExt_End		
	END