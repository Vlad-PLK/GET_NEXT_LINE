<p align="center>
  <h1>**GET NEXT LINE**</h1>  
</p>

In this project, I created a function that returns every next line of a text file each time we call it.
The prototype looks like this : 
\
```C
char	*get_next_line(int fd)
{
	...
	return (line);
}
```
As you can see it takes a file descriptor as argument and returns a char string.
The file descriptor corresponds to the open file you wanna read from.
Here is an example of get_next_line function :
