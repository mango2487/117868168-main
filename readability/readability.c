#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// PROBLEM your word count function is shit fix it

int count_letters(const char* text);
int count_words(const char* text);
int count_sentence(const char* text);

int main(void)
{

  string text = get_string("Text: ");
  int letterc = count_letters(text);
  int wordc   = count_words(text);
  int sentencec = count_sentence(text);

  // formula ((index = 0.0588 * L - 0.296 * S - 15.8))

 float result = 0.0588 * ((float)letterc / wordc) * 100 - 0.296 * ((float)sentencec / wordc) * 100 - 15.8;
 printf("Char count:%d\nWord count:%d\nSentence count:%d\n", letterc, wordc, sentencec);

  if (result < 1)
  {
    printf("Before Grade 1\n");
  }

  else if (result >= 16)
  {
    printf("Grade 16+\n");
  }

  else
  {
    printf("Grade %.0f\n", result);
  }

  return 0;

}

int count_letters(const char* text)
{
    int letterc = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
     if (isalpha(text[i]))
     {
        letterc ++;
     }
    }
 return letterc;
}


int count_words(const char* text)
{
    int wordc = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if ((i == 0 || isspace(text[i - 1])) && isalpha(text[i]))
        {
            wordc++;
        }
    }

    return wordc;
}


int count_sentence(const char* text)
{
 int sentencec = 0;

 for (int i = 0; text[i] != '\0'; i++)
 {
   if (text[i] == '.')
   {
     sentencec ++;
   }
 }
 return sentencec;

}
// get a string input to be graded [Y]
// implement function count_letters & sentence & word [Y]
// Set and figure out variables L & S within the passage (letters, words, sentences) [Y]
// plug into formula (index = 0.0588 * L - 0.296 * S - 15.8) [Y]
// spit out result [Y]
// is it correct [not really(word variable)]