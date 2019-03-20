char* longestCommonPrefix(char** strs, int strsSize)
{
	if(!strsSize)
	{
		return "";
	}
    int len, i, j;
    for(len = 0; strs[0][len]; len++);
    for(i = 1; i < strsSize; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(strs[i][j] == '\0' || strs[i][j] != strs[0][j])
            {
                len = j;
                break;
            }
        }
    }
    char *ret = malloc(len + 1);
    for(i = 0; i < len; i++)
    {
        ret[i] = strs[0][i];
    }
    ret[len] = '\0';
    return ret;
}
