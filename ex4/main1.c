#include <stdio.h>

int main()
{
    FILE* fp;
    int a[] = {0,1,2}; 
    char b[] = "ABC";
    float c[] = {1.1,1.2,1.3};
    int ra[3];
    char rb[4];
    float rc[3];
    if ((fp = fopen("a.bin", "wb+")) == NULL){
        printf("Can not open the file...\n");
        return(1);
    }
    
    if (fwrite(a, sizeof(a), 1, fp) !=1||
        fwrite(b, sizeof(b), 1, fp) !=1||
        fwrite(a, sizeof(a), 3, fp) !=1){
        printf("Write file error\n");
    }
    fseek(fp, 0, SEEK_SET);

    if (fread(ra, sizeof(ra), 1, fp) !=1||
        fread(rb, sizeof(rb), 1, fp) !=1||
        fread(rc, sizeof(rc), 1, fp) !=1){
        printf("Read file error\n");
        }

    for (int i=0; i<3;i++){
        printf("%d", ra[i]);
    } 
    printf("\n");
    printf("%s\n",rb);
    
    for (int i=0; i<3;i++){
        printf("%f", rc[i]);
    } 
    printf("\n");
    fclose(fp);
return 0;

}
 
