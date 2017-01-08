#include <stdlib.h>
#include <stdio.h>

char* fileName;
char* endFileName;

FILE *filp;
FILE *endFilp;

void OpenFile();

void OpenTargetFile();

void SetUpFiles();

void Encrypt();

void Decrypt();

int main(int argc, char *argv[])
{

  int choice;

  fileName = (char *)malloc(100 * sizeof(char));
  endFileName = (char *)malloc(100 * sizeof(char));

  printf("This is a file encryption program\nAuthor: Saxon Supple\n");

  SetUpFiles();

  do{
    printf("Type 1 for encrypt and 2 for decrypt: ");
    
    scanf("%d", &choice);

    if(choice == 1)
      Encrypt();
    else if(choice == 2)
      Decrypt();
    else
      printf("Idiot\n");
  }while(choice != 1 && choice != 2);
  
  if(fclose(filp) == 0)
    printf("File Closed\n");

  else
    printf("Error: File can't be closed\n");

  if(fclose(endFilp) == 0)
    printf("File Closed\n");

  else
    printf("Error: File can't be closed\n");
  
  free(fileName);
  free(endFileName);
  
  filp = NULL;
  endFilp = NULL;
  
  return 0;
}

void OpenFile(){
  printf("Enter a file name that you want encrypted/decrypted: ");

  scanf("%s", fileName);

  printf("%s\n", fileName); 

  filp = fopen(fileName, "r");
}

void OpenTargetFile(){
  printf("Enter a file name for the encrypted/decrypted file: ");

  scanf("%s", endFileName);

  printf("%s\n", endFileName); 

  endFilp = fopen(endFileName, "w");
}

void SetUpFiles(){
  while(filp == NULL){
    OpenFile();

    if(filp == NULL)
      printf("Error: File does not exist\n");

    else
      printf("File opened\n");
  }

  while(endFilp == NULL){
    OpenTargetFile();

    if(endFilp == NULL)
      printf("Error: could not open file\n");

    else
      printf("File opened\n");
  }
}

void Encrypt()
{
  int c;

  printf("Encrypting\n");
  
  while (c != EOF){
    c = (fgetc (filp));
    
    fputc(c+100, endFilp);
  }
}

void Decrypt()
{
  int c;

  printf("Decrypting\n");
  
  while (c != EOF){
    c = (fgetc (filp));
    printf("%d", c);
    fputc(c-100, endFilp);
  }
}
