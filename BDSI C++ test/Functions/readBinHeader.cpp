#include <stdio.h>

class readBinHeader{

	struct header{
		int version;
		long wfmSize;
		long noteSize;
		long pictSize;
		short checksum
		long formulaSize;
		long dataEUnitsSize;
		long dimEUnitsSize;
		long dimLabelsSize;
		long sIndicesSize;
		long optionsSize1;
		long optionsSize2;
	}
	struct header readIBWbinheader(string FFN){
		int MAXDIMS = 4;
		File *fid = fopen(FFN,"r");
		struct header H;
		fread(&H.version,2,1,fid);
		switch(H.version){
			case 2:
			fread(&H.wfmSize,4,1,fid); 
        	fread(&H.noteSize,4,1,fid); 
        	fread(&H.pictSize,4,1,fid);
        	fread(&H.checksum,2,1,fid);
        	break;
        	case 5:
        	fread(&H.checksum,sizeof(short),1,fid);
	        fread(&H.wfmSize,sizeof(long),1,fid); 
	        fread(&H.formulaSize,sizeof(long),1,fid);   
	        fread(&H.noteSize,sizeof(long),1,fid);   
	        fread(&H.dataEUnitsSize,sizeof(long),1,fid);  
	        fread(&H.dimEUnitsSize,sizeof(long),1,fid);  
	        fread(&H.dimLabelsSize,sizeof(long),1,fid); 
	        fread(&H.sIndicesSize,sizeof(long),1,fid); 
	        fread(&H.optionsSize1,sizeof(long),1,fid); 
	        fread(&H.optionsSize2,sizeof(long),1,fid);
	        break;
	        default:
	        break;
		}
		fclose(fid);
}

}