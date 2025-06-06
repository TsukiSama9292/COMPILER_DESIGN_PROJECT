int num1 = 1;
int num2 = 2;

int max = 0;
int min = 0;
int sum = 0;

int x = 5;
int y = 3;

int done = 0;
int jump = 1;

while(done<jump){
	if(num1>num2){
        x=x+1;
        done=done+1;
    }
	else{ 
        y=y+1;
        done=done+1;
    }
}

while(x>y){
    if(x>y){
        max=x;
        min=y;
        sum=max+min;
        x=0;
        y=0;
    }
    else{
        max=y;
        min=x;
        sum=max+min;
        x=0;
        y=0;
    }
}
