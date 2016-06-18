#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
T StringToNumber (const string &Text,T defValue = T())
{
    stringstream ss;
    for ( string::const_iterator i=Text.begin(); i!=Text.end(); ++i )
        if ( isdigit(*i) || *i=='e' || *i=='-' || *i=='+' || *i=='.' )
            ss << *i;
    T result;
    return ss >> result ? result : defValue;
}


struct dependency
{
	int type;
	string reg;
	string inst_src;
	string inst_dest;
	int i_src;
	int i_dest;
};

int main()
{
	int counter =0;
	char Instructions[30][30];
	char MemAddress[30][30], MemVal[30][30];
	char dest[30][30],source1[30][30],source2[30][30];
	string Instruction[30];
	string MemAddresses[30],MemVals[30];
	string destination[30],src1[30],src2[30];
	string filename="";
	int num_instr=0,num_accesses=0;
	string num;
	dependency dep[30],new_dep[30];
	ifstream in;
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<10;j++)
		{
			Instructions[i][j]='\0';
			MemAddress[i][j]='\0';
			MemVal[i][j]='\0';
			dest[i][j]='\0';
			source1[i][j]='\0';
			source2[i][j]='\0';
		}
	}
	do
	{
		in.clear();
		cout << "Enter the name of the file" << endl;
		cin >> filename;
		in.open(filename.c_str());
	}while(!in);
	do
	{
		char temp='q';
		in.get(temp);
		if(temp=='-')
		{
			do
			{
				in.get(temp);
			}while(temp!='\n');
		}
		else
		{
			if(temp=='F' || temp=='f' || temp=='A' || temp=='a' || temp=='S' || 
			temp=='s' || temp=='L' || temp=='l' || temp=='M' || temp=='m' ||
			temp=='B' || temp=='b' || temp=='H' || temp=='h')  
			{
				Instructions[counter][0]=temp;
				int j=1;
				char temp2;
				do
				{
					in.get(temp2);
					if(temp2!='\n')
					{
						if(temp2!=' ')
						{
							Instructions[counter][j]=temp2;
							j++;
						}
					}
				}while(temp2!=' '&&temp2!='\n');
				do
				{
					if(temp2==' ' || temp2=='\t')
						in.get(temp2);
				}while(temp2==' ' || temp2=='\t');
				if(Instructions[counter][0]=='F' || Instructions[counter][0]=='A' ||
				Instructions[counter][0]=='S' || Instructions[counter][0]=='f' ||
				Instructions[counter][0]=='a' || Instructions[counter][0]=='s')
				{
					int k=0;
					if((Instructions[counter][0]=='S' || Instructions[counter][0]=='s') &&
					(Instructions[counter][1]=='T'||Instructions[counter][1]=='t'))
					{
						source1[counter][k]=temp2;
						k++;
						do
						{
							in.get(temp2);
							if(temp2!=',')
							{
								source1[counter][k]=temp2;
								k++;
							}
						}while(temp2!=',');
						k=0;
						do
						{
							in.get(temp2);
							if(temp2==' ' || temp2=='\t')
							{
								do
								{
									in.get(temp2);
								}while(temp2==' ' || temp2=='\t');
							}
							if(temp2!='\n')
							{
								if(temp2=='-')
								{
									if(source2[counter][k-1]!='#')
									{
										do
										{
										in.get(temp2);
										}while(temp2!='\n');
									}
									else
									{
										source2[counter][k]=temp2;
										k++;
									}
								}
								else
								{
									source2[counter][k]=temp2;
									k++;
								}
							}
						}while(temp2!='\n');
						dest[counter][0]=' ';
					}
					else
					{
						dest[counter][k]=temp2;
						k++;
						do
						{
							in.get(temp2);
							if(temp2!=',')
							{
								dest[counter][k]=temp2;
								k++;
							}
						}while(temp2!=',');
						k=0;
						do
						{
							in.get(temp2);
							if(temp2==' ' || temp2=='\t')
							{
								do
								{
									in.get(temp2);
								}while(temp2==' ' || temp2=='\t');
							}
							if(temp2!=',')
							{
								source1[counter][k]=temp2;
								k++;
							}
						}while(temp2!=',');
						k=0;
						do
						{
							in.get(temp2);
							if(temp2==' ' || temp2=='\t')
							{
								do
								{
									in.get(temp2);
								}while(temp2==' ' || temp2=='\t');
							}
							if(temp2!='\n')
							{
								if(temp2=='-')
								{
									if(source2[counter][k-1]!='#')
									{
										do
										{
										in.get(temp2);
										}while(temp2!='\n');
									}
									else
									{
										source2[counter][k]=temp2;
										k++;
									}
								}
								else
								{
									source2[counter][k]=temp2;
									k++;
								}
							}
						}while(temp2!='\n');
					}
				}
				else if(Instructions[counter][0]=='L' || Instructions[counter][0]=='l' ||
				Instructions[counter][0]=='M' || Instructions[counter][0]=='m')
				{
					int k=0;
					dest[counter][k]=temp2;
					k++;
					do
					{
						in.get(temp2);
						if(temp2!=',')
						{
							dest[counter][k]=temp2;
							k++;
						}
					}while(temp2!=',');
					k=0;
					do
					{
						in.get(temp2);
						if(temp2==' ' || temp2=='\t')
						{
							do
							{
								in.get(temp2);
							}while(temp2==' ' || temp2=='\t');
						}
						if(temp2!='\n')
						{
							if(temp2=='-')
							{
								if(source2[counter][k-1]!='#')
								{
									do
									{
									in.get(temp2);
									}while(temp2!='\n');
								}
								else
								{
									source2[counter][k]=temp2;
									k++;
								}								
							}
							else
							{
								source2[counter][k]=temp2;
								k++;
							}
						}
					}while(temp2!='\n');
					source1[counter][0]=' ';
				}
				else if(Instructions[counter][0]=='B' || Instructions[counter][0]=='b')
				{
					int k=0;
					if((Instructions[counter][0]=='B' || Instructions[counter][0]=='b') &&
					(Instructions[counter][1]=='R'||Instructions[counter][1]=='r'))
					{
						source2[counter][k]=temp2;
						k++;
						do
						{
							in.get(temp2);
							if(temp2!='\n')
							{
								if(temp2=='-')
								{
									if(source2[counter][k-1]!='#')
									{
										do
										{
										in.get(temp2);
										}while(temp2!='\n');
									}
									else
									{
										source2[counter][k]=temp2;
										k++;
									}
								}
								else
								{
									source2[counter][k]=temp2;
									k++;
								}
							}
						}while(temp2!='\n');
						dest[counter][0]=' ';
						source1[counter][0]=' ';
					}
					else
					{
						int k=0;
						source1[counter][k]=temp2;
						k++;
						do
						{
							in.get(temp2);
							if(temp2!=',')
							{
								source1[counter][k]=temp2;
								k++;						
							}
						}while(temp2!=',');
						k=0;
						do
						{
							in.get(temp2);
							if(temp2==' ' || temp2=='\t')
							{
								do
								{
									in.get(temp2);
								}while(temp2==' ' || temp2=='\t');
							}
							if(temp2!='\n')
							{
								if(temp2=='-')
								{
									if(source2[counter][k-1]!='#')
									{
										do
										{
										in.get(temp2);
										}while(temp2!='\n');
									}
									else
									{
										source2[counter][k]=temp2;
										k++;
									}
								}
								else
								{
									source2[counter][k]=temp2;
									k++;
								}
							}
						}while(temp2!='\n');
						dest[counter][0]=' ';
					}
				}
				counter++;
			}
			else
			{
				if(temp!='<')
				{
					int j=1;
					char temp2;
					num[0]=temp;
					do
					{
						in.get(temp2);
						if(temp2!=' ')
						{
							num[j]=temp2;
							j++;
						}
					}while(temp2!=' ');
					do
					{
						in.get(temp2);
					}while(temp2!='\n'&&!in.eof());
					if(num_instr==0)
					{
						if(j==1)
						{	
							num_instr = num[0]-48;
							j=1;
						}
						else if(j==2)
						{	
							num_instr = (num[0]-48)*10 + (num[1]-48);
							j=1;
						}
					}
					else
					{
						if(j==1)
						{
							num_accesses = num[0]-48;
							j=1;
						}
						else if(j==2)
						{
							num_accesses = (num[0]-48)*10 + (num[1]-48);
							j=1;
						}
					}
				}
				else
				{
					int counter2=0;
					int k=0;
					int l=0;
					char temp2;
					do
					{
						in.get(temp2);
						cout << temp2 << endl;
						if(temp2!='>')
						{
							MemAddress[counter2][l]=temp2;
							l++;
						}
					}while(temp2!='>');
					do
					{
						in.get(temp2);
					}while(temp2!='<');
					do
					{
						in.get(temp2);
						cout << temp2 << endl;
						if(temp2!='>')
						{
							MemVal[counter2][k]=temp2;
							k++;
						}
					}while(temp2!='>');
					do
					{
						in.get(temp2);
					}while(!in.eof()&&temp2!='\n');
					counter2++;
					cout << "ends here" << endl;
				}
			}
		}
	}while(!in.eof());  

	in.close();
	for(int i=0; i<30;i++)
	{
		Instruction[i]=string(Instructions[i]);
		destination[i]=string(dest[i]);
		src1[i]=string(source1[i]);
		src2[i]=string(source2[i]);
		MemAddresses[i]=string(MemAddress[i]);
		MemVals[i]=string(MemVal[i]);
	}
	
	int dep_counter=0;
	for(int i=0; i<num_instr;i++)
	{
 		if(Instruction[i]=="FPADD" || Instruction[i]=="FPSUB" || 
		Instruction[i]=="FPMULT" || Instruction[i]=="FPDIV" || Instruction[i]=="ADD"
		|| Instruction[i]=="SUB" || Instruction[i]=="LOAD" || Instruction[i]=="MOV")
		{ 
			if(i!=(num_instr)-1)
			{
				for(int j=i+1; j<num_instr;j++)
				{
 				if(destination[i]==src1[j] || dest[i]==src2[j])  //RAW DEPENDENCIES
					{
						if((j-i)<8)
						{
							dep[dep_counter].type = 1;
							dep[dep_counter].reg = dest[i];
							dep[dep_counter].i_src = i;
							dep[dep_counter].inst_src = Instruction[i];
							dep[dep_counter].i_dest = j;
							dep[dep_counter].inst_dest = Instruction[j];
							dep_counter++;
						}
					}
					if(destination[i]==destination[j])  //WAW DEPENDENCIES
					{
						if((j-i)<8)
						{
							dep[dep_counter].type = 2;
							dep[dep_counter].reg = dest[i];
							dep[dep_counter].i_src = i;
							dep[dep_counter].inst_src = Instruction[i];
							dep[dep_counter].i_dest = j;
							dep[dep_counter].inst_dest = Instruction[j];
							dep_counter++;
						}
					}
				}
			}
		}
	}

	for(int i = (num_instr)-1; i>=0;i--)
	{
		if(Instruction[i]=="FPADD" || Instruction[i]=="FPSUB" || 
		Instruction[i]=="FPMULT" || Instruction[i]=="FPDIV" || Instruction[i]=="ADD"
		|| Instruction[i]=="SUB" || Instruction[i]=="LOAD" || Instruction[i]=="MOV")
		{
			if(i!=0)
			{
				for(int j=i-1; j>=0;j--)
				{
					if(destination[i]==src1[j] || destination[i]==src2[j])  //WAR DEPENDENCIES
					{
						if((i-j)<8)
						{
							dep[dep_counter].type = 3;
							dep[dep_counter].reg = dest[i];
							dep[dep_counter].i_src = i;
							dep[dep_counter].inst_src = Instruction[i];
							dep[dep_counter].i_dest = j;
							dep[dep_counter].inst_dest = Instruction[j];
							dep_counter++;
						}
					}
				}
			}
		}
	}
	
	
	for(int i=0;i<dep_counter;i++)
	{
		cout << dep[i].type << ", " << dep[i].reg << ", " 
		<< dep[i].inst_src << " " << dep[i].i_src << ", " 
		<< dep[i].inst_dest << " " << dep[i].i_dest << endl;;
	}
	
	int rename=0;
 	for(int i=0; i<num_instr;i++)
	{
 		if(Instruction[i]=="FPADD" || Instruction[i]=="FPSUB" || 
		Instruction[i]=="FPMULT" || Instruction[i]=="FPDIV" || Instruction[i]=="ADD"
		|| Instruction[i]=="SUB" || Instruction[i]=="LOAD" || Instruction[i]=="MOV")
		{ 
			if(i!=(num_instr)-1)
			{
				for(int j=i+1; j<num_instr;j++)
				{
					if(destination[i]==destination[j])  //WAW DEPENDENCIES register renaming
					{
						if((j-i)<8)
						{
							switch(rename)
							{
								case 0:
									destination[j] = "R15";
									if(j!=num_instr-1)
									{
										for(int k=j; k<num_instr;k++)
										{
											if(src1[k]==destination[i])
											{
												src1[k] = "R15";
											}
											if(src2[k]==destination[i])
											{
												src2[k] = "R15";
											}
										}
									}
									rename++;
									break;
								case 1:
									destination[j] = "R14";
									if(j!=num_instr-1)
									{
										for(int k=j; k<num_instr;k++)
										{
											if(src1[k]==destination[i])
											{
												src1[k] = "R14";
											}
											if(src2[k]==destination[i])
											{
												src2[k] = "R14";
											}
										}
									}
									rename++;
									break;
								case 2:
									destination[j] = "R13";
									if(j!=num_instr-1)
									{
										for(int k=j; k<num_instr;k++)
										{
											if(src1[k]==destination[i])
											{
												src1[k] = "R13";
											}
											if(src2[k]==destination[i])
											{
												src2[k] = "R13";
											}
										}
									}
									rename++;
									break;
								case 3:
									destination[j] = "R12";
									if(j!=num_instr-1)
									{
										for(int k=j; k<num_instr;k++)
										{
											if(src1[k]==destination[i])
											{
												src1[k] = "R12";
											}
											if(src2[k]==destination[i])
											{
												src2[k] = "R12";
											}
										}
									}
									rename++;
									break;
								case 4:
									destination[j] = "R11";
									if(j!=num_instr-1)
									{
										for(int k=j; k<num_instr;k++)
										{
											if(src1[k]==destination[i])
											{
												src1[k] = "R11";
											}
											if(src2[k]==destination[i])
											{
												src2[k] = "R11";
											}
										}
									}
									rename++;
									break;
								case 5:
									destination[j] = "R10";
									if(j!=num_instr-1)
									{
										for(int k=j; k<num_instr;k++)
										{
											if(src1[k]==destination[i])
											{
												src1[k] = "R10";
											}
											if(src2[k]==destination[i])
											{
												src2[k] = "R10";
											}
										}
									}
									rename++;
									break;
							}
						}
					}
				}
			}
		}
	}
	
	for(int i = (num_instr)-1; i>=0;i--) //Register Renaming
	{
		if(Instruction[i]=="FPADD" || Instruction[i]=="FPSUB" || 
		Instruction[i]=="FPMULT" || Instruction[i]=="FPDIV" || Instruction[i]=="ADD"
		|| Instruction[i]=="SUB" || Instruction[i]=="LOAD" || Instruction[i]=="MOV")
		{
			if(i!=0)
			{
				for(int j=i-1; j>=0;j--)
				{
					if(destination[i]==src1[j] || destination[i]==src2[j])  //WAR DEPENDENCIES
					{
						if((i-j)<8)
						{
							switch(rename)
							{
								case 0:
									destination[i] = "R15";
									if(i!=num_instr-1)
									{
										for(int k=i; i<num_instr;k++)
										{
											if(src1[k]==src1[j] || src1[k]==src2[j])
											{
												src1[k] = "R15";
											}
											if(src2[k]==src1[j] || src2[k]==src2[j])
											{
												src2[k] = "R15";
											}
										}
									}
									rename++;
									break;
								case 1:
									destination[i] = "R14";
									if(i!=num_instr-1)
									{
										for(int k=i; k<num_instr;k++)
										{
											if(src1[k]==src1[j] || src1[k]==src2[j])
											{
												src1[k] = "R14";
											}
											if(src2[k]==src1[j] || src2[k]==src2[j])
											{
												src2[k] = "R14";
											}
										}
									}
									rename++;
									break;
								case 2:
									destination[i] = "R13";
									if(i!=num_instr-1)
									{
										for(int k=i; k<num_instr;k++)
										{
											if(src1[k]==src1[j] || src1[k]==src2[j])
											{
												src1[k] = "R13";
											}
											if(src2[k]==src1[j] || src2[k]==src2[j])
											{
												src2[k] = "R13";
											}
										}
									}
									rename++;
									break;
								case 3:
									destination[i] = "R12";
									if(i!=num_instr-1)
									{
										for(int k=i; k<num_instr;k++)
										{
											if(src1[k]==src1[j] || src1[k]==src2[j])
											{
												src1[k] = "R12";
											}
											if(src2[k]==src1[j] || src2[k]==src2[j])
											{
												src2[k] = "R12";
											}
										}
									}
									rename++;
									break;
								case 4:
									destination[i] = "R11";
									if(i!=num_instr-1)
									{
										for(int k=i; k<num_instr;k++)
										{
											if(src1[k]==src1[j] || src1[k]==src2[j])
											{
												src1[k] = "R11";
											}
											if(src2[k]==src1[j] || src2[k]==src2[j])
											{
												src2[k] = "R11";
											}
										}
									}
									rename++;
									break;
								case 5:
									destination[i] = "R10";
									if(i!=num_instr-1)
									{
										for(int k=j; k<num_instr;k++)
										{
											if(src1[k]==src1[j] || src1[k]==src2[j])
											{
												src1[k] = "R10";
											}
											if(src2[k]==src1[j] || src2[k]==src2[j])
											{
												src2[k] = "R10";
											}
										}
									}
									rename++;
									break;
									case 6:
										destination[i] = "R9";
										if(i!=num_instr-1)
										{
											for(int k=j; k<num_instr;k++)
											{
												if(src1[k]==src1[j] || src1[k]==src2[j])
												{
													src1[k] = "R9";
												}
												if(src2[k]==src1[j] || src2[k]==src2[j])
												{
													src2[k] = "R9";
												}
											}
										}
										rename++;
										break;
									case 7:
										destination[i] = "R8";
										if(i!=num_instr-1)
										{
											for(int k=j; k<num_instr;k++)
											{
												if(src1[k]==src1[j] || src1[k]==src2[j])
												{
													src1[k] = "R8";
												}
												if(src2[k]==src1[j] || src2[k]==src2[j])
												{
													src2[k] = "R8";
												}
											}
										}
										rename++;
										break;
									case 8:
									destination[i] = "R7";
									if(i!=num_instr-1)
									{
										for(int k=j; k<num_instr;k++)
										{
											if(src1[k]==src1[j] || src1[k]==src2[j])
											{
												src1[k] = "R7";
											}
											if(src2[k]==src1[j] || src2[k]==src2[j])
											{
												src2[k] = "R7";
											}
										}
									}
									rename++;
									break;
							}
						}
					}
				}
			}
		}
	}
	
	
	cout << endl << endl;
	
	int dep_count=0;
	for(int i=0; i<num_instr;i++) //Rechecking dependencies
	{
 		if(Instruction[i]=="FPADD" || Instruction[i]=="FPSUB" || 
		Instruction[i]=="FPMULT" || Instruction[i]=="FPDIV" || Instruction[i]=="ADD"
		|| Instruction[i]=="SUB" || Instruction[i]=="LOAD" || Instruction[i]=="MOV")
		{ 
			if(i!=(num_instr)-1)
			{
				for(int j=i+1; j<num_instr;j++)
				{
					if(destination[i]==src1[j] || dest[i]==src2[j])  //RAW DEPENDENCIES
					{
						if((j-i)<8)
						{
							new_dep[dep_count].type = 1;
							new_dep[dep_count].reg = dest[i];
							new_dep[dep_count].i_src = i;
							new_dep[dep_count].inst_src = Instruction[i];
							new_dep[dep_count].i_dest = j;
							new_dep[dep_count].inst_dest = Instruction[j];
							dep_count++;
						}
					}
					if(destination[i]==destination[j])  //WAW DEPENDENCIES
					{
						if((j-i)<8)
						{
							new_dep[dep_count].type = 2;
							new_dep[dep_count].reg = dest[i];
							new_dep[dep_count].i_src = i;
							new_dep[dep_count].inst_src = Instruction[i];
							new_dep[dep_count].i_dest = j;
							new_dep[dep_count].inst_dest = Instruction[j];
							dep_count++;
						}
					}
				}
			}
		}
	}

	for(int i = (num_instr)-1; i>=0;i--)
	{
		if(Instruction[i]=="FPADD" || Instruction[i]=="FPSUB" || 
		Instruction[i]=="FPMULT" || Instruction[i]=="FPDIV" || Instruction[i]=="ADD"
		|| Instruction[i]=="SUB" || Instruction[i]=="LOAD" || Instruction[i]=="MOV")
		{
			if(i!=0)
			{
				for(int j=i-1; j>=0;j--)
				{
					if(destination[i]==src1[j] || destination[i]==src2[j])  //WAR DEPENDENCIES
					{
						if((i-j)<8)
						{
							new_dep[dep_count].type = 3;
							new_dep[dep_count].reg = dest[i];
							new_dep[dep_count].i_src = i;
							new_dep[dep_count].inst_src = Instruction[i];
							new_dep[dep_count].i_dest = j;
							new_dep[dep_count].inst_dest = Instruction[j];
							dep_count++;
						}
					}
				}
			}
		}
	}
	float R[16];  //Registers
	for(int i=0;i<16;i++) //initializing
	{
		R[i] = 0;
	}
	float Memory[1024];			//Memory
	for(int i=0;i<1024;i++)//initializing
	{
		Memory[i] = 0;
	}
	int PC=0;
	std::string::size_type sz;
	int i_destination;
	int i_src1;
	int i_src2int;
	int Memory_address;
	float Value;
	float i_src2;
	
	for(int i=0;i<num_accesses;i++) // Memory Accesses
	{
		Memory_address = StringToNumber<int>(MemAddress[i],0.0);
		Value = StringToNumber<int>(MemVal[i],0.0);
		Memory[Memory_address] = Value;
		//cout << "Memory Address: " << Memory_address << " contains: " << Memory[Memory_address] << endl;
	}
	
		int count[30],count1[30],count2[30],count3[30],count4[30],count5[30],count6[30],count7[30],count8[30],count9[30];
	for(int i=0;i<30;i++)
	{
		count[i]=0;
		count1[i]=0;
		count2[i]=0;
		count3[i]=0;
		count4[i]=0;
		count5[i]=0;
		count6[i]=0;
		count7[i]=0;
		count8[i]=0;
		count9[i]=0;
		
	}
		
	for(int i=0; i<num_instr-1;i++)
	{
		
		int number = src2[i][1] - 48;
		if(Instruction[i]=="FPADD")
		{	
			cout<<"I am here"<<endl;
			count[i]+=3;
			cout<<count[i]<<endl;
		}
		
		else if(Instruction[i]=="FPMULT")
		{
			if(src2[i][0]=='#') //errors
			{
				if(src2[i][1]=='-'||src2[i][1]=='1'||src2[i][1]=='0') //errors
				{
				count1[i]+=1;
				cout<<count1[i]<<endl;
				}
			
				else if(number%2==0)
				{
				count1[i]+=2;
					cout<<count1[i]<<endl;
				}
				
			}
			else
			{
				count1[i]+=5;
				cout<<count1[i]<<endl;
			}
		}
		else if(Instruction[i]=="FPSUB")
		{
			count2[i]+=3;
			
		}
		else if(Instruction[i]=="FPDIV")
		{
			count3[i]+=8;
		}	
		else if(Instruction[i]=="ADD")
		{
			count4[i]+=1;
			
		}	
		else if(Instruction[i]=="SUB")
		{
			count5[i]+=1;
		}	
		else if(Instruction[i]=="LOAD")
		{
			count6[i]+=1;
		}	
		else if(Instruction[i]=="STR")
		{
			count7[i]+=3;
		}	
		else if(Instruction[i]=="MOV")
		{
			count8[i]+=1;
		}	
		else
		{
			count9[i]+=1;
		}
	}
		for(int i=0;i<num_instr-1;i++)
		{
			if(new_dep[i].type == 1)
				{
					if(new_dep[i].inst_src == "FPMULT")
					{
						
						for(int j=i+1;i<num_instr;j++)
						{
							if(Instruction[j]==new_dep[i].inst_dest)
							{
								for(int k=0; k<5;k++)
								{
									//pause
								}
							}
							
							else
							{
								if(Instruction[j]=="FPMULT")
								{
											i_destination = StringToNumber<int>(destination[i],0.0);
											i_src1 = StringToNumber<int>(src1[i],0.0);
											i_src2 = StringToNumber<float>(src2[i],0.0);
									if(src2[i][0]=='R')
									{
										i_src2int = i_src2;
										R[i_destination] = R[i_src1] * R[i_src2int];
									}
									else if(src2[i][0]=='#')
									{
										R[i_destination] = R[i_src1] * i_src2;
									}
									else
									{
										i_src2int = i_src2;
										R[i_destination] = R[i_src1] * Memory[i_src2int];
									}
								}
		
								else if(Instruction[j]=="FPADD")
								{
									i_destination = StringToNumber<int>(destination[i],0.0);
									i_src1 = StringToNumber<int>(src1[i],0.0);
									i_src2 = StringToNumber<float>(src2[i],0.0);
										if(src2[i][0]=='R')
									{
										i_src2int = i_src2;
										R[i_destination] = R[i_src1] + R[i_src2int];
									}
									else if(src2[i][0]=='#')
									{
									R[i_destination] = R[i_src1] + i_src2;
									}
									else
									{
										i_src2int = i_src2;
										R[i_destination] = R[i_src1] + Memory[i_src2int];
									}
			
								}
								else if(Instruction[j]=="FPSUB")
								{
									i_destination = StringToNumber<int>(destination[i],0.0);
									i_src1 = StringToNumber<int>(src1[i],0.0);
									i_src2 = StringToNumber<float>(src2[i],0.0);
									if(src2[i][0]=='R')
									{
										i_src2int = i_src2;
										R[i_destination] = R[i_src1] - R[i_src2int];
									}
									else if(src2[i][0]=='#')
									{
										R[i_destination] = R[i_src1] - i_src2;
									}
									else
									{
										i_src2int = i_src2;
										R[i_destination] = R[i_src1] - Memory[i_src2int];
									}
			
								}
								else if(Instruction[j]=="FPDIV")
								{
								i_destination = StringToNumber<int>(destination[i],0.0);
								i_src1 = StringToNumber<int>(src1[i],0.0);
								i_src2 = StringToNumber<float>(src2[i],0.0);
									if(src2[i][0]=='R')
									{
											i_src2int = i_src2;
											R[i_destination] = R[i_src1] / R[i_src2int];
									}
									else if(src2[i][0]=='#')
									{
										R[i_destination] = R[i_src1] / i_src2;
									}
									else
									{
											i_src2int = i_src2;
											R[i_destination] = R[i_src1] / Memory[i_src2int];
									}
			
								}
								else if(Instruction[j]=="ADD")
								{
								i_destination = StringToNumber<int>(destination[i],0.0);
								i_src1 = StringToNumber<int>(src1[i],0.0);
								i_src2 = StringToNumber<float>(src2[i],0.0);
								if(src2[i][0]=='R')
								{
									i_src2int = i_src2;
									R[i_destination] = R[i_src1] + R[i_src2int];
								}
								else if(src2[i][0]=='#')
								{
									R[i_destination] = R[i_src1] + i_src2;
								}
								else
								{
									i_src2int = i_src2;
									R[i_destination] = R[i_src1] + Memory[i_src2int];
								}
								}
								else if(Instruction[j]=="SUB")
								{
								i_destination = StringToNumber<int>(destination[i],0.0);
								i_src1 = StringToNumber<int>(src1[i],0.0);
								i_src2 = StringToNumber<float>(src2[i],0.0);
								if(src2[i][0]=='R')
								{
									i_src2int = i_src2;
									R[i_destination] = R[i_src1] - R[i_src2int];
								}
								else if(src2[i][0]=='#')
								{
									R[i_destination] = R[i_src1] - i_src2;
								}
								else
								{
									i_src2int = i_src2;
									R[i_destination] = R[i_src1] - Memory[i_src2int];
								}
								}
								else if(Instruction[j]=="LOAD")
								{
								i_destination = StringToNumber<int>(destination[i],0.0);
								i_src2 = StringToNumber<float>(src2[i],0.0);
								if(src2[i][0]=='#')
								{
									R[i_destination] =  i_src2;
								}
								else
								{
									i_src2int = i_src2;
									R[i_destination] = Memory[i_src2int];
								}
			
								}
								else if(Instruction[j]=="MOV")
							{
							i_destination = StringToNumber<int>(destination[i],0.0);
							i_src2 = StringToNumber<float>(src2[i],0.0);
							i_src2int = i_src2;
								R[i_destination] =  R[i_src2int];
							}
						else if(Instruction[j]=="STR")
						{
							i_src1 = StringToNumber<int>(src1[i],0.0);
							i_src2 = StringToNumber<float>(src2[i],0.0);
							if(src2[i][0]=='#')
							{
								i_src2int = i_src2;
								Memory[i_src2int] =  i_src1;
							}
							else
							{
									i_src2int = i_src2;
									Memory[i_src2int] =  Memory[i_src1];
							}
			
						}
					}
				}
			}
		}
	}
return 0;
}		
			