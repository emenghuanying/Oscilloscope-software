// FON.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "GBK16.h"
#include "string.h"

#define PING "ƻ"

/* data defines */
static char name_buffer[20][200];
static unsigned char read_buffer[10*1024*1024];
/* hz */
static unsigned char hz_buf[10000][32];
static unsigned short hz_index[10000];
static unsigned char hz_original[5000];
static unsigned int hz_original_cnt = 0;
static unsigned int hz_cnt = 0;
/* find hz */
int find_all_hz(unsigned char * hzb,unsigned int len)
{
	char * str_pos = (char *)hzb;
	/* �ҵ��ؼ��ֶ� */
	while(1)
	{
		/* �ҵ��ؼ�λ�� */
		char * pos = strstr(str_pos,(const char *)"GBK2312_ASSETS_HZ16");
		/* ��ȡ���� */
		if( pos != NULL )
		{
			/* �ؼ��ֳ��� */
			int slen = strlen("GBK2312_ASSETS_HZ16");
			/* ��ȡλ�� */
			unsigned char * spos = (unsigned char *)pos + slen;
			/* �жϸ�ʽ */
			if( spos[0] != '(' || spos[1] != '"' )
			{
				printf("format error \r\n");
				/* ֱ�ӷ��� */
				return (-1);
			}
			/* ��λ������λ�� */
			spos += 2;
			/* copy data */
			int j = 0;
			/* tes */
			for( j = 0 ; spos[j] != '"' ; j ++ )
			{
				hz_original[hz_original_cnt] = spos[j];
				hz_original_cnt++;
			}
			/* �жϳ��ȣ�������Ǻ���Ӧ����ż���ֽ���*/
			if( hz_original_cnt % 2 )
			{
				printf("len error \r\n");
				/* ֱ�ӷ��� */
				return (-1);
			}
			/* str_pos_i */
			str_pos = pos + slen;
		}
		else
		{
			/* return break */
			return hz_original_cnt;
		}
	}
}
/* get offset from gbk2312 */
int get_gbk_offset(char * hz_code)
{
	/* hz_code */
	unsigned char high = hz_code[0];
	unsigned char low = hz_code[1];
#if 0
	printf("high:%x, low:%x\n", high, low);
#endif	
	if (low < 0x80)
	{
		return ((high-0x81)*190 + (low-0x40))*32;
	}
	else
	{
		return ((high-0x81)*190 + (low-0x41))*32;
	}
}
/* Tchar to char */
int Tchar_to_char(_TCHAR * tchar,char * buffer)
{
    int i = 0;
	/* set buffer to zero */
	memset(buffer,0,sizeof(buffer));
	/* offset */
	while( *tchar != '\0' )
	{
       buffer[i] = (char)(*tchar);
	   tchar ++;
	   i++;
	}
	/* return  */
	return i;
}
/*------------------*/
int _tmain(int argc, _TCHAR* argv[])
{
	/* ת��TCHAR to char * */
  	for(int i = 1 ; i< argc ; i++ )
	{
       Tchar_to_char(argv[i],name_buffer[i-1]);
	}
#if 0
	memcpy(name_buffer[0],"hz_lib.c",8);
	memcpy(name_buffer[1],"hz_out.h",8);
#endif
	/* �򿪵�һ��λ�õ��ļ� */
	FILE * dir_file;
	/* */
	fopen_s(&dir_file,name_buffer[0],"rb");
	/* ���ļ��Ƿ�ɹ� */
    if( dir_file == NULL )
	{
		/* ��ʧ��ֱ���жϣ���ӡ��Ϣ */
		printf("Can not open this file: %s,please check it up\r\n");
		/* break */
		return 0;
	}
	/* ���ļ�ȫ����ȡ���� ��ǰ���ǲ��ܴ���10M */
	int len = fread(read_buffer,1,sizeof(read_buffer),dir_file);
	/* �ļ��ر� */
	fclose(dir_file);
	/* �ж��ļ��Ƿ����10MB ����������򲻽��д��� */
	if( len >= sizeof(read_buffer) )
	{
		printf("file is over 10MB ,can not supply \r\n");
		/* �ж� */
		return 0;
	}
	/* �������ļ����ҵ�������Ҫ�����ĺ��� */
	int ret = find_all_hz(read_buffer,len);
	/* ת�����м仺�� */
	for( int i = 0 ; i < ret  ; i += 2 )
	{
		int offset = get_gbk_offset((char *)&hz_original[i]);
		/* ��ȡ��ģ���� */
		for( int j = 0 ; j < 32 ; j ++ )
		{
			hz_buf[hz_cnt][j] = _acGBK16[ j + offset ];
		}
		/* ��ȡindex */
		hz_index[hz_cnt] = *((unsigned short *)&hz_original[i]);
		/* hz ++ */
		hz_cnt ++;
	}
	/* create out file */
	FILE * file_create;
	/* �����ļ� */
	fopen_s(&file_create,name_buffer[1],"wb+");
    /* ����ļ�����ʧ����ֱ���˳� */
	if( file_create == NULL )
	{
		printf("This file create failed:%s\r\n",name_buffer[1]);
		/* ֱ�ӷ��� */
		return (-1);
	}
	/* �ļ������ɹ� */
	char s_buf[100];
    #define HEADER "/* \r\n	This file created by software automatic , do not change \r\n*/"
    #define INDEX_HEADER "\r\nconst unsigned short HZ_INDEX[] = \r\n{\r\n" 
    #define INDEX_TAIL "\r\n};\r\n"
    #define ENTER_CTRL_T  "\r\n"
	/* д�����ļ� */
	fwrite(HEADER,1,strlen(HEADER),file_create);
	/* д����ͷ�ļ� */
	fwrite(INDEX_HEADER,1,strlen(INDEX_HEADER),file_create);
	/* static unsisgned */
	static unsigned int enter_ctrl = 0;
	/* ѭ��д���� */
	for( unsigned int i = 0 ; i < hz_cnt ; i ++ )
	{
		/* ����д������� */
		sprintf_s(s_buf,"0x%04x,",hz_index[i]);
		/* д���ļ� */
		fwrite(s_buf,1,strlen(s_buf),file_create);
        /* д��س����ݵ�ʱ�� */
		enter_ctrl ++ ;
		/* ÿ8������д��һ������ */
		if( enter_ctrl >= 8 )
		{
		   enter_ctrl = 0;
		   fwrite(ENTER_CTRL_T,1,strlen(ENTER_CTRL_T),file_create);
		}
	}
	/* д���ļ���β */
	fwrite(INDEX_TAIL,1,strlen(INDEX_TAIL),file_create);
	/* write dtata */
	#define DATA_HEADER "const unsigned char HZ_DATAX[][32] = \r\n{\r\n"
	#define DATA_TAIL "};\r\n"
    #define DATA_GROUP "{\r\n"
    #define DATA_GROUPEND "},\r\n"
    #define DATA_COMMON "\r\n/* HZ data */ \r\n"
	/* �����ļ� */
	enter_ctrl = 0;
	/* д��ע���ļ� */
	fwrite(DATA_COMMON,1,strlen(DATA_COMMON),file_create);
    /* д����ͷ�ļ� */
	fwrite(DATA_HEADER,1,strlen(DATA_HEADER),file_create);
	/* ѭ��д����ģ���� */
	for( unsigned int i = 0 ; i < hz_cnt ; i ++ )
	{
		/* д��������� */
		fwrite(DATA_GROUP,1,strlen(DATA_GROUP),file_create);
		/* ------------ */
		/* ����д������� */
		for( int j = 0 ; j < 32 ; j ++ )
		{
		   sprintf_s(s_buf,"0x%02x,",hz_buf[i][j]);
		   /* д���ļ� */
		   fwrite(s_buf,1,strlen(s_buf),file_create);
		   /* д��س����ݵ�ʱ�� */
		   enter_ctrl ++ ;
		   /* ÿ8������д��һ������ */
		   if( enter_ctrl >= 8 )
		   {
			   enter_ctrl = 0;
			   fwrite(ENTER_CTRL_T,1,strlen(ENTER_CTRL_T),file_create);
		   }
		}
		/* д��������� */
		fwrite(DATA_GROUPEND,1,strlen(DATA_GROUPEND),file_create);
		/* ------------ */
	}
	/* д���β���� */
	fwrite(DATA_TAIL,1,strlen(DATA_TAIL),file_create);
	
	fclose(file_create);

	printf("OK HZ are %d\r\n",hz_cnt);
    /*int oname_buffer[1]ffset = get_gbk_offset(PING);

	printf("%d,%s",argc,argv[0]);
	unsigned char hz_dd[32];

	for(int i = 0; i < 32; i++)
	{
		hz_dd[i] = _acGBK16[offset+i];
	}

	FILE * ddt = fopen("hz_lib.c","rb");

	if( ddt == 0 )
	{
		printf("error\r\n");
		return 0;
	}

	int len = fread(buffer_h,1,sizeof(buffer_h),ddt);
	char hz_b[100];

	for( int i = 0 ; i < len ; i ++ )
	{
		if ( sscanf(&buffer_h[i],"GBK2312_HZ16(\"%s\");",hz_b) )
		{
			printf("%d\r\n",i);
		}
	}*/

	return 0;
}

