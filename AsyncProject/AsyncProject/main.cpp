//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )//����ʾ����̨��������������Ҳһ��
#include <stdlib.h>
#include <conio.h>

#include <ProToolkit.h>
#include <ProCore.h>

int main(int argc,char *argv[])
{
	printf("�����Ự��...\n");
	ProEngineerStart("C:\\PTC\\Creo 2.0\\Parametric\\bin\\parametric.exe","");
	printf("�Ự����������������رջỰ���˳�������...\n");
	_getch();
	printf("�����Ự�������˳�...\n");
	ProEngineerEnd();
	return 0;
}
