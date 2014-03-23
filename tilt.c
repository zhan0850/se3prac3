/*
  Takes a list of <length> integers, and attempts to shift them left
  according to the rules of 2048.

  The shift is always to the left.  If the caller wants to shift to
  the right instead, they should reverse the list order.

  This means pairs of identical numbers with no other number inbetween
  get merged together.  But the same tile may not be involved in more
  than one merge.
*/

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // Mark all tiles as not combined
  int i;
  int *combinedP[length];
  for(i=0;i<length;l++) combined[i]=0;

}
