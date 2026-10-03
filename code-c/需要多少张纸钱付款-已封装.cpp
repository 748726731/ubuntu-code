  #include<stdio.h>
			  void hanshu2(int one,int two,int sum);
					  void hanshu3(int one,int sum)
					  {
					  	for(int two=0;two*2<=sum;two++)
					  		{
					  			hanshu2(one,two,sum);
							}
					  }
								  void hanshu4(int sum)
								  {
								  	for(int one=0;one*1<=sum;one++)
								  	{
								  	hanshu3(one,sum);
									}
								  }
  int main()
  {
  	int sum;
  	printf("总价为：");
  	scanf("%d",&sum);
  	hanshu4(sum);
	return 0;
  }
  
  void hanshu2(int one,int two,int sum)
			  {
			  for(int five=0;five*5<=sum;five++)
			  			{
			  					if(one*1+two*2+five*5==sum)
								  {
	  							printf("需要一元%d张，需要二元%d张，需要5元%d张\n",one,two,five);
								  }
						}
			  }
