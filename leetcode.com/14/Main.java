class Solution
{
    public String longestCommonPrefix(String[] strs)
    {
        if(strs.length == 0)
        {
            return "";
        }
        int len = strs[0].length();
        for(int i = 1; i < strs.length; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(j >= strs[i].length() || strs[i].charAt(j) != strs[0].charAt(j))
                {
                    len = j;
                    break;
                }
            }
        }
        return strs[0].substring(0, len);
    }
}