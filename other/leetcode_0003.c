/*Given a string s, find the length of the longest substring without repeating characters.*/

int lengthOfLongestSubstring(char * s){
    int cnt = 0;
    int maxLen = 0;
    struct bitmap{
        unsigned long long bitmap_upper;
        unsigned long long bitmap_lower;
    }bitmap_record,bitmapString;

    unsigned long long long1 = 1;
    unsigned long long long0 = 0;

    bitmap_record.bitmap_upper = long0;
    bitmap_record.bitmap_lower = long0;

    for(int i,j = (0,0);s[i]!='\0';){
        bitmapString.bitmap_lower &= long0;
        bitmapString.bitmap_upper &= long0;
        if (s[i] < 64){
            bitmapString.bitmap_lower = long1<<(s[i]);
        }
        else{
            bitmapString.bitmap_upper = long1<<(s[i]-64);
        }
        if((bitmapString.bitmap_lower & bitmap_record.bitmap_lower) == long0 && (bitmapString.bitmap_upper & bitmap_record.bitmap_upper) == long0){
            if (s[i] < 64){
                bitmap_record.bitmap_lower |= bitmapString.bitmap_lower;
            }
            else {
                bitmap_record.bitmap_upper |= bitmapString.bitmap_upper;
            }
            i++;
        }
        else{
            if (s[j] < 64){
                bitmap_record.bitmap_lower &= ~(long1 << s[j]);
            }
            else {
                bitmap_record.bitmap_upper &= ~(long1 << s[j]-64);
            }
            j++;
        }
        cnt = i - j;
        maxLen = (maxLen < cnt? cnt:maxLen);
    }
    return maxLen;
}
