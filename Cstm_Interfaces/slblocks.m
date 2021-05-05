function blkStruct = slblocks
		% This function specifies that the library should appear
		% in the Library Browser
		% and be cached in the browser repository

		Browser.Library = 'cstm_interfaces_lib';
		% 'cstm_interfaces_lib' is the name of the library

		Browser.Name = 'Cstm_Interfaces';
		% 'Cstm_Interfaces' is the library name that appears 
             % in the Library Browser

		blkStruct.Browser = Browser; 