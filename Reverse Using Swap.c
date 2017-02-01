/***********************************************************************
* FILENAME : String Reverse
*
* DESCRIPTION : This code sample reverses a string. 
*
* AUTHOR : Patrick Dempsey      
*
**********************************************************************/

int main(void)
{
    char buffer [] = {"Reverse this string."};
    
	printf("%s\n", buffer);
	
	char character=0;  //holding space for jumping characters
    int i,len,halfLen;

    len = strlen(buffer);
    halfLen = len/2;

    //reverse the characters in string
    for(i=0;i<halfLen;i++)
    {
        character = buffer[i];
        buffer[i] = buffer[len-1 - i];
        buffer[len-1 - i] = character;
    }
    printf(buffer);

return 0;   
}
