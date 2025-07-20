class Solution {
public:
    int FindNextNonSpace(const char *Str, int Index)
    {
        while (Str[Index] != '\0') {
            if (Str[Index] != ' ') {
                return Index;
            }
            
            Index++;
        }
        
        return Index;
    }
    
    int FindNextNonNumber(const char *Str, int Index, bool &IsAllZeros)
    {
        IsAllZeros = true;
        while (Str[Index] != '\0') {
            if ((Str[Index] < '0') || (Str[Index] > '9')) {
                return Index;
            }
            
            if (Str[Index] != '0') {
                IsAllZeros = false;
            }
            
            Index++;
        }
        
        return Index;
    }
    
    bool isNumber(const char *s)
    {
        int Length;
        Length = strlen(s);
        if (Length == 0) {
            return false;
        }
    
        bool Ret;
        int Index = 0;
        Index = FindNextNonSpace(s, Index);
        if (Index == Length) {
            return false;
        }
    
        if ((s[Index] == '+') || (s[Index] == '-')) {
            Index++;
        }
    
        bool FoundFirstPart = false;
        bool FoundSecondPart = false;
        bool FoundEPart = false;
        bool HasFirstPart = false;
        bool IsFirstPartZero = true;
        bool IsSecondPartZero = true;
        int IndexTemp;
    
        while (Index < Length) {
            if ((s[Index] >= '0') && (s[Index] <= '9')) {
                if (FoundFirstPart == true) {
                    return false;
                }
    
                IndexTemp = Index;
                Index = FindNextNonNumber(s, Index, IsFirstPartZero);
                HasFirstPart = (Index > IndexTemp);
                FoundFirstPart = true;
    
            } else if (s[Index] == '.') {
                if ((FoundSecondPart == true) || (FoundEPart == true)) {
                    return false;
                }
    
                Index++;
                IndexTemp = Index;
                Index = FindNextNonNumber(s, Index, IsSecondPartZero);
                if ((Index == IndexTemp) && (HasFirstPart == false)) {
                    return false;
                }
    
                FoundFirstPart = true;
                FoundSecondPart = true;
    
            } else if (s[Index] == 'e') {
                if ((FoundEPart == true) || (FoundFirstPart == false)) {
                    return false;
                }
    
                Index++;
                if ((s[Index] == '+') || (s[Index] == '-')) {
                    Index++;
                }
    
                bool Temp;
                IndexTemp = Index;
                Index = FindNextNonNumber(s, Index, Temp);
                if (Index == IndexTemp) {
                    return false;
                }
    
                FoundEPart = true;
    
            } else if (s[Index] == ' ') {
                Index = FindNextNonSpace(s, Index);
                if (Index != Length) {
                    return false;
                }
    
            }else {
                return false;
            }
        }
    
        return FoundFirstPart;
    }   
};