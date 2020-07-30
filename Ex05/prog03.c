#include <stdio.h>
#include <string.h>

int checkString(char *);

int main()
{
  int i;
  char newsstring[6][15]={"Good News", "Bad News", "Happy News", 
              "Sweet News", "Scary News", "Wonderful News"};

  for(i = 0; i < 6; i++) {
    /* If a string contains the patterns "Bad" or "Scary", 
       replace it with the new string "Cool News". */
   /* ここを作成する */
    if(checkString(newsstring[i])==1){
        strcpy(newsstring[i],"Cool News");
    }
  }
  
  /* Print out the result */
  printf("--\n");
  for(i = 0; i < 6; i++) printf("%2d %s\n",i ,newsstring[i]);
  printf("--\n");
  
  return 0;
}

/* Check whether a string contains the patterns "Bad" or "Scary" 
   at the first n characters using strncmp function */
/* Refer to the command "man strcmp" for the strncmp function. */
int checkString(char *str)
{
   /* ここを作成する */  
   //printf("%s\n",str);
    if(strncmp("Bad",str,3)==0){
        return 1;
    }else if(strncmp("Scary",str,5)==0){
        return 1;
        }
        else{
            return 0;
        }
}
