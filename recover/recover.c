#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
// check if the argument count is 2
{
  if (argc != 2)
  {
    printf("Usage: .recover/ image\n");
    return 1;
  }

  // open file for reading
  FILE *input_file = fopen(argv[1],"r");
  if (input_file == NULL)
  {
    printf("Error opening input_file\n");
    return 2;
  }

  // store 512 bytes in arrays
  unsigned char buffer [512];

  // track number of images generated
  int count_images = 0;

  // file pointer for recovered images

  FILE * output_file = NULL;

  //char filename allocate memory
  char *filename = malloc(8 * sizeof(char));

  // read blocks of 512 bytes
  while(fread(buffer, sizeof(char), 512, input_file))
  {
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
      if(count_images > 0)
      {
        fclose(output_file);
      }
      // write JPEG filenames
      sprintf(filename, "%03i.jpg", count_images);

      // open output_file
      output_file = fopen(filename, "w");

      // count number of images found
      count_images++;
    }
    // check if output has been used for valid input
    if(output_file != NULL)
    {
      fwrite(buffer, sizeof(char), 512, output_file);
    }
  }
fclose(input_file);
fclose(output_file);
free(filename);

return 0;
}







// {
//     FILE *
//     *buffer1 = 0;
//     *buffer2 = 0;
//     fopen("card.raw","r");
//     if ()
//     fread(*buffer1, 512, [], * card.raw);
//     if (card[0] == 0xff && card[1] == 0xd8 && card[2] == 0xff && card[3] == 1110)
//     {
//         fopen("000.jpg", "w");
//         for (int)
//         fwrite(*buffer2, 512, [], * 000.jpg);
//     }


//   fclose();
//   return 1;
// }

