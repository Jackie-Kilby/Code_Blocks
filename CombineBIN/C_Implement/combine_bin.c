#include "stdio.h"

#define BUFFER_SIZE 1024
int main(void)
{
	printf("Combine BINs here.\r\n");
	FILE *bin1,*bin2,*resbin;
	unsigned char buf[BUFFER_SIZE];
	int rc1;
	
	if((bin1 = fopen("test.bin","rb"))!=NULL) {
		resbin = fopen("combin.bin","wb");
		printf("Open BIN-1 success.\r\n");
		while((rc1 = fread(buf,sizeof(unsigned char),BUFFER_SIZE,bin1))!=0) {
			fwrite(buf, sizeof(unsigned char),rc1, resbin);
		}
		
		//Fill will 0xFF until 0x40000
		while (ftell(resbin)<0x40000) {
			buf[0] = 0xFF;
			fwrite(buf, sizeof(unsigned char), 1, resbin);
		}

		if((bin2 = fopen("user.bin","rb"))!=NULL) {
			fseek(resbin, 0x40000L, SEEK_SET);
			printf("Open BIN-2 success.\r\n");
			while((rc1 = fread(buf,sizeof(unsigned char),BUFFER_SIZE,bin2))!=0) {
				fwrite(buf, sizeof(unsigned char),rc1, resbin);
			}
		} else {
			printf("Open BIN-2 fail.\r\n");
		}
	} else {
		printf("Open BIN-1 fail.\r\n");
	}

	fclose(bin1);
	fclose(bin2);
	fclose(resbin);

	return 0;
}

