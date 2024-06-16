int my_strlen(char *ps)
{
    int cnt = 0;
    while (*ps != '\0')
    {
        cnt++;
        ps++;
    }
    return cnt;
}