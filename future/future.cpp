#include"std_lib_facilities.h"
#include"magic_numb.h"
string re_str(string ss);
string get_date(string period);

int main()
{

	string lines;

	string file_name1 = "C:\\Users\\Air\\Desktop\\摩根\\摩根项目\\Future Trade Sample_Commodities.csv";
	ifstream is1(file_name1);
	getline(is1, lines);

	while (getline(is1, lines))
	{
		string replace;

		int trade_numb;//1000001
		char trade_type;//S B
		string future_product;//WTI
		string period;//17-jul

		double user_price;
		double quantity;

		double balance;//cha e 

		replace = re_str(lines);
		istringstream is(replace);
		is >> trade_numb;
		is >> trade_type;
		is >> future_product;
		is >> period;
		is >> user_price;
		is >> quantity;
		if (trade_type == 'B')
		{
			if (future_product == "WTI")
			{
				period = get_date(period);
				if (period == "Jul")
				{
					balance = WTI_Jul - user_price;
				}
				else if (period=="Aug")
				{
					balance = WTI_Aug - user_price;
				}
				else if (period == "Sep")
				{
					balance = WTI_Sep - user_price;
				}
				else if (period == "Oct")
				{
					balance = WTI_Oct - user_price;
				}
				else if (period == "Nov")
				{
					balance = WTI_Nov - user_price;
				}
				else if (period == "Dec")
				{
					balance = WTI_Dec - user_price;
				}
			}
			else if (future_product == "BRENT")
			{
				period = get_date(period);
				if (period == "Jul")
				{
					balance = BRENT_Jul - user_price;
				}
				else if (period == "Aug")
				{
					balance = BRENT_Aug - user_price;
				}
				else if (period == "Sep")
				{
					balance = BRENT_Sep - user_price;
				}
				else if (period == "Oct")
				{
					balance = BRENT_Oct - user_price;
				}
				else if (period == "Nov")
				{
					balance = BRENT_Nov - user_price;
				}
				else if (period == "Dec")
				{
					balance = BRENT_Dec - user_price;
				}
			}
		}
		else if (trade_type == 'S')
		{
			if(future_product == "WTI")
			{
				period = get_date(period);
				if (period == "Jul")
				{
					balance = -WTI_Jul + user_price;
				}
				else if (period == "Aug")
				{
					balance = -WTI_Aug + user_price;
				}
				else if (period == "Sep")
				{
					balance = -WTI_Sep + user_price;
				}
				else if (period == "Oct")
				{
					balance = -WTI_Oct + user_price;
				}
				else if (period == "Nov")
				{
					balance = -WTI_Nov + user_price;
				}
				else if (period == "Dec")
				{
					balance = -WTI_Dec + user_price;
				}
			}
			else if (future_product == "BRENT")
			{
				period = get_date(period);
				if (period == "Jul")
				{
					balance = -BRENT_Jul + user_price;
				}
				else if (period == "Aug")
				{
					balance = -BRENT_Aug + user_price;
				}
				else if (period == "Sep")
				{
					balance = -BRENT_Sep + user_price;
				}
				else if (period == "Oct")
				{
					balance = -BRENT_Oct + user_price;
				}
				else if (period == "Nov")
				{
					balance = -BRENT_Nov + user_price;
				}
				else if (period == "Dec")
				{
					balance = -BRENT_Dec + user_price;
				}
			}
		}
		cout << "The order number is : " << trade_numb << endl;
		cout << "The profit is : " << balance*quantity<<endl;
		cout<<endl;
	}
	is1.close();

	keep_window_open();
	return 0;
}

string re_str(string ss)
{
	string replace;
	for (int i = 0; i < ss.size(); i++)
	{
		if (ss[i] == ',')
		{
			replace = replace + " ";
		}
		else
			replace = replace + ss[i];
	}
	return replace;
}
string get_date(string period)
{
	string str1;
	for (int i = 0; i < period.size(); i++)
	{
		if (period[i] == '-')
		{
			str1 = str1 + " ";
		}
		else
			str1 = str1 + period[i];
	}
	string date;
	int year;
	
	istringstream is(str1);
	is >> year;
	
	if (!is)
	{
		is.clear();
	}
	is >> date;

	return date;
}