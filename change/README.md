The "change" program makes change for any country’s monetary system (real or ﬁctional). This program accepts, as command-line parameters,
the coin denominations that make up the monetary system, and the total value. It then prints a report of the combination of coins needed
to make up the total, from highest to lowest denomination. For example if a particular country has coins with values 1, 10, and 25, and 
you have 68 units of money, then the command-line would read as follows:

./change 1 10 25 68

The initial three values are the coin denominations, in any order. The last value is the total. For this input, the output should be:
2 x 25 

1 x 10 

8 x 1

Notes: 
• Most coin systems have the property that you can make change by starting at the highest coin value, taking as many of those as possible, and then moving on to the next coin value, and so on. Assume that the input for change will always have this property. 
• If it is not possible to construct the given total, outputs Impossible to standard output.
• The program needs at least 2 command-line parameters: a minimum of one denomination and one total.
• Valid command-line parameters are positive integers.
• Denominations may be listed in any order. Supports at most 10 denominations.
