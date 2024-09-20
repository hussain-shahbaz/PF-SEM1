#include<iostream>
using namespace std;
main()
{
	cout<<"enter your name";
	string name;
	cin>>name;
	cout<<"Enter Matric Marks..(out of 1100)";
	float m_marks;
	cin>>m_marks;
	cout<<"Enter floater(first year marks out of 550)..";
	float float_marks;
	cin>>float_marks;
	cout<<"enter ECAT score..(out of 400)";
	float ECAT;
	cin>>ECAT;
	float m_perc = (m_marks/1100);
	float float_perc =  (float_marks/550);
	float ECAT_perc = (ECAT/400);

	float aggregate ;
	aggregate = m_perc* 10 + float_perc* 40 + ECAT_perc* 50;
	cout<<name<<"'s aggregate is . "<< aggregate << "%";
	
}