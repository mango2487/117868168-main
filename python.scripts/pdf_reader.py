#import module PyPDF2
import PyPDF2
#put example.pdf in working directory
# open it in read binary mode
pdfFileObj = open('example.pdf,'rb')
# to print the total number of pages in pdf
# print(pdfReader.numPages)
# get speciic page by passing specific number (acessing list)
pageObj = pdfReader.getPage(0)
# extract the page object
# by extractText() function
print(texts)