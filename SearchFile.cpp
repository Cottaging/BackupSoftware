#include "SearchFile.h"

static Search* instance;

Search* Search::getInstance()
{
	if (instance == NULL)
		instance = new Search();
	return instance;
}

//�����ļ����µ��ļ����б�(����Ƕ���ļ���)
void Search::GetFileList(char *dir, vector<string> &filelist)
{
	cout << "-----------File Searching-----------" << endl;
	/****************/
	struct stat s;

	if (stat(dir, &s) == 0) {
		if (s.st_mode & S_IFDIR) {
			std::cout << "[test] it's a directory" << std::endl;
		}
		else if (s.st_mode & S_IFREG) {
			std::cout << "[test] it's a file" << std::endl;
			filelist.push_back(dir);
			cout << dir << endl;
			return;
		}
		else {
			std::cout << "[test] not file not directory" << std::endl;
			return;
		}
	}
	else {
		std::cout << "[test] error, doesn't exist" << std::endl;
		return;
	}
	/****************/
	HANDLE Fhead;
	WIN32_FIND_DATAA fileData;
	string data;
	char Fname[MAX_PATH_LEN],tmp[MAX_PATH_LEN];
	strcpy(Fname, dir);

	//����·����
	if (Fname[strlen(Fname) - 1] != '\\')
		strcat(Fname, "\\");
	strcpy(tmp, Fname);
	//cout << "[test] tmp:" << tmp << endl;
	strcat(Fname, "*"); //����*�����

	Fhead = FindFirstFileA(Fname, &fileData);
	FindNextFile(Fhead, &fileData);
	while (FindNextFile(Fhead, &fileData))
	{
		//��ΪĿ¼
		if (fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//�������ж�DIR
		{
			if (fileData.cFileName[0] != '.')
			{
				char szFile[MAX_PATH_LEN];
				strcpy(szFile, tmp);
				strcat(szFile, fileData.cFileName);
				//cout << "[test] szFile:" << szFile << endl;
				GetFileList(szFile, filelist);
			}
		}
		//��Ϊ��ͨ�ļ�
		else
		{
			data = (string)tmp;
			data += fileData.cFileName;
			/*if (data.find(".h",0)!=string::npos)
			{
			filelist.push_back(data);
			}
			else
			{
			continue;
			}*/
			filelist.push_back(data);
		}
		cout<<data<<endl;
	}
	return;
}
