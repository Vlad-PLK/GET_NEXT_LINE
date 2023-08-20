<p>
  <h1 align="center">GET NEXT LINE</h1>
</p>

In this project, I created a function that returns every next line of a text file each time we call it.
The prototype looks like this :

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

```C
int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDWR);
	/// we use printf directly to display the char string returned by get_next_line ///
	printf("Here is the first line of the file text : %s", get_next_line(fd));	
}
```
<p align="center">
	<img width="100%" alt="first_example" src="https://github.com/Vlad-PLK/GET_NEXT_LINE/assets/61476758/8012cc11-fb7e-4e0b-8b6b-14c166f16d6c">
</p>
In the picture above, you can firstly notice that we compiled with a flag "-D BUFFER_SIZE=10". BUFFER_SIZE is a variable corresponding to the number of characters read each time by read function. It means that we've made a function get_next_line that returns the first next line of a text file even if BUFFER_SIZE is a very large number or if it's equal to 1. That was a specific rule mentioned in our subject.
Right after the compilation line you can see that text.txt contains 2 lines and finally right after the cat call you see that gnl returned only the first line. 
\
Here's a second example with multiple lines and multiple calls of this function :

```C
int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDWR);
	printf("Here is the first line of the file text : %s", get_next_line(fd));
	printf("Here is the second line of the file text : %s", get_next_line(fd));
	printf("Here is the third line of the file text : %s", get_next_line(fd));
	printf("Here is the fourth line of the file text : %s", get_next_line(fd));
	printf("Here is the last line of the file text : %s", get_next_line(fd));
}
```
<p align="center">
	<img width="100%" alt="second_example" src="https://github.com/Vlad-PLK/GET_NEXT_LINE/assets/61476758/819a18d6-ab29-4ec5-9612-8a560dc04c33">
</p>

