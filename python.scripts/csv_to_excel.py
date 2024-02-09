# start by installing 'pip intall openpyxl' ?

#!python3
# -*- coding utf-8 -*-

import openpyxl
import sys

#inputs
print("This programme writes the data in any Comma-separated value file (such as: .csv or .data) to a Excel file.")
print("The input and output files must be in the same directory of the python file for the programme to work.\n")

csv_name = input("name of the csv file for input (with the extension): ")
sep = input("sepporator of the csv file: ")
excel_name = input("Name of the excel file for output (with the extension): ")
sheet_name = input("name of the excel sheet for output: ")

#opening the files
try:
    wb = openpyxl.load_workbook(excel_name)
    sheet = wb.get_sheet_by_name(sheet_name)

    file = open(csv_name, "r",encoding = "utf-8")
except:
    print("FIle open error!")
    sys.exit

# rows & columns
row = 1
column = 1

#for each line in the file
for line in file:
    # remove the \n and make it a comma seperated list
    line = line[:-1]
    line = line.split(sep)

    #for each data in the line
    for data in line:
        #write the data to excel
        sheet.cell(row,column).value = data
        # after each data column increase by 1
        column += 1
        # to write the next line set column to 1 and increment row by +=1
        column = 1
        row += 1

    # saving the excel file and close the csv file
    wb.save(excel_name)
    file.close()


