#include <read_file.h>

using namespace std;

#define MAX_PICTURES_EACH_TIME 60

int read_file( vector<char*> *files_name_reoder ,const char* FILE_PATH)
{
	// set address variable
	DIR * dir;
    	struct dirent * ptr;
	vector<string> files_name;
	vector<long long> files_time;
	
	string file_path(FILE_PATH);
	// open a file directory
	if( (dir = opendir(FILE_PATH)) == NULL )
	{
		printf("failed when open directory .\n");
		return 1;
	}
	//printf(" Succeed when open directory .\n");
	cout << " Path of pictures : \t\t" << file_path << endl;

	// read the directory
	//int i = 0;
	while( (ptr = readdir(dir)) != NULL )
	//while( (ptr = readdir(dir)) != NULL && i <= MAX_PICTURES_EACH_TIME ) 
	{
		//if  (0 != strcmp(strchr(ptr->d_name, '.'), ".jpg"))
		if ((0 == strncasecmp(ptr->d_name, ".", 1)) || (0 != strcmp(strchr(ptr->d_name, '.'), ".jpg")))
			continue;
		
		// get name and time 
		string file_name = ptr->d_name;
		string newstring = file_name.substr( 0, file_name.size()-4 );

		stringstream newstring_name;
		newstring_name << newstring;
		
		long long file_time=0;
		newstring_name >> file_time;

		files_time.push_back( file_time );
		file_name  = file_path + file_name;
		files_name.push_back( file_name );
		//i++;

	}
	closedir(dir);
	//printf(" The sum of files is %d this time.\n",int(files_name.size()));
	//printf(" Succeed when read directory .\n");
	if ( files_name.size() == 0 )
	{
	cout<<" Find no file ... "<<endl;
	return 1;
	}
	
	
	if (files_name.size() != 0)
	{
		// re_order
		for ( int i=0; i<int(files_time.size()); i++ )
		{
			for( int j=i+1; j<int(files_time.size()); j++  )
			{
				if ( files_time[i] > files_time[j] )
				{
				string name = files_name[i];
				long long time = files_time[i];
				files_name[i] = files_name[j];
				files_time[i] = files_time[j];
				files_name[j] = name;
				files_time[j] = time;
				}
			}
		}
		
		// copy to file_name_order
		for( int i=0;  i<int(files_name.size()); i++ )
		{
			char* c;
   			const int len = files_name[i].length();
   			c = new char[len+1];
   			strcpy(c,files_name[i].c_str());
	
			files_name_reoder->push_back( c );		
		}

	}


	return 0;
};
