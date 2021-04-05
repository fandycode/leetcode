int* diffWaysToCompute(char * expression, int* returnSize){
    if(expression == NULL){
        *returnSize = 0;
        return NULL;
    }
    int len = strlen(expression);
    int idx = 0;
    int calflag = 0;
    int* returnArray = (int *)malloc(sizeof(int) * 1);;
    int returnCnt = 0;
    char * leftStr = (char *)malloc(sizeof(char) * len);
    char * rightStr = (char *)malloc(sizeof(char) * len);

	for(idx = 0;idx < len;++idx)
	{
		if((expression[idx] == '+') || (expression[idx] == '-') || (expression[idx] == '*'))
		{
			calflag = 1;
			memcpy(leftStr,expression,idx);
			leftStr[idx] = '\0';
			memcpy(rightStr,expression + idx + 1,len - idx - 1);
			rightStr[len - idx - 1] = '\0';
			int leftReturnSize = 0;
			int rightReturnSize = 0;
			int* leftRet = diffWaysToCompute(leftStr, &leftReturnSize);
			int* rightRet = diffWaysToCompute(rightStr, &rightReturnSize);
			returnArray = (int*)realloc(returnArray,sizeof(int) * (returnCnt + leftReturnSize * rightReturnSize));
			for(int i = 0; i < leftReturnSize; i++){
				for(int j = 0; j < rightReturnSize; j++){
					switch(expression[idx]){
						case '+':
							returnArray[returnCnt++] = leftRet[i] + rightRet[j];
							break;
						case '-':
							returnArray[returnCnt++] = leftRet[i] - rightRet[j];
							break;
						case '*':
							returnArray[returnCnt++] = leftRet[i] * rightRet[j];
							break;
						default:
							break;
					} 
				}
			}
			free(leftRet); 
            free(rightRet);
		}
	}

    if(calflag == 0){
        *returnSize = 1;
        returnArray[0] = atoi(expression);
    }else{
        *returnSize = returnCnt;
    }
    return returnArray;
}
