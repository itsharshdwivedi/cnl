#include<string.h>
#include<stdio.h>

char text[20],key[20],rem[20];
void crc()
{
  int i,j,keylen,textlen;
  char temp[100];
  
  strcpy(temp,text);
  keylen=strlen(key);
  
  for(i=0;i<keylen-1;i++)
    strcat(temp,"0");
  
  textlen=strlen(temp);
  strncpy(rem,temp,keylen);
  
  while(i!=textlen)
  {
    if(rem[0]=='0')
    {
      strcpy(rem,&rem[1]);
      rem[keylen-1]=temp[++i];
      rem[keylen]='\0';
      continue;
    }
    for(j=0;j<keylen;j++)
      rem[j]=((rem[j]-'0')^(key[j]-'0'))+'0';
    }
}

void main()
{
  int i,choice;
  
  while(1)
  {
    printf("\n1.Find CRC\n2.Check CRC\n3.Quit\nEnter the choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
      case 1:
              printf("Enter the input:\n");
              scanf("%s",text);
              printf("Enter the key:\n");
              scanf("%s",key);
              crc();
              printf("Msg: %s \n",strcat(text,rem));
              break;
      case 2:
              printf("Enter the input:");
              scanf("%s",text);
              printf("\nEnter key:");
              scanf("%s",key);
              crc();
              for(i=0;i<strlen(key)-1;i++)
                if(rem[i]=='1')
                break;
              if(i==strlen(key)-1)
                printf("NO ERROR\n");
              else
                printf("ERROR");
              break;
      case 3:
              exit(0);
    }
  }
}
