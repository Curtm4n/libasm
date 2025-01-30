#include <stdio.h>
#include <unistd.h>
#include <errno.h>

extern int		ft_strlen(char *str);
extern char		*ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(char *s1, char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);

int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "world!";
	char str3[] = "";
	char str4[] = "une chaine un petit peu plus longue";

	//TEST FT_STRLEN
	printf("TESTS FT_STRLEN:\n\n");

	printf("taille de la chaine \"%s\": %d\n", str1,  ft_strlen(str1));
	printf("taille de la chaine \"%s\": %d\n", str2,  ft_strlen(str2));
	printf("taille de la chaine \"%s\": %d\n", str3,  ft_strlen(str3));
	printf("taille de la chaine \"%s\": %d\n", str4,  ft_strlen(str4));


	//TEST STRCPY
	printf("\n\nTESTS FT_STRCPY:\n\n");

	char buffer1[100] = "buffer1 vide";
	char buffer2[100] = "buffer2 vide";

	printf("buffer1 avant copie: \"%s\"\n", buffer1);
	printf("Copie de \"%s\" dans buffer1: \"%s\"\n", str1, ft_strcpy(buffer1, str1));

	printf("\nbuffer2 avant copie: \"%s\"\n", buffer2);
	printf("Copie de \"%s\" dans buffer2: \"%s\"\n", str2, ft_strcpy(buffer2, str2));

	//TEST FT_STRCMP
	printf("\n\nTESTS FT_STRCMP:\n\n");

	char *str5 = "a";
	char *str6 = "b";

	printf("s1 est %s\ns2 est %s\n", str5, str6);
	printf("difference entre s1 et s2: %d\n", ft_strcmp(str5, str6));
	printf("difference entre s2 et s1: %d\n", ft_strcmp(str6, str5));

	//TEST FT_WRITE
	printf("\n\nTESTS FT_WRITE:\n\n");

	ssize_t ret;

	ret = ft_write(1, "Hello world!\n", 14);
	printf("Retour de ft_write: %zd\n", ret);

	// Test avec fd invalide
	ret = ft_write(-1, "Test\n", 5);
	if (ret == -1)
		perror("Erreur de ft_write");
	printf("Retour de ft_write (fd invalide): %zd, errno: %d\n", ret, errno);

	//TEST FT_READ
	printf("\n\nTESTS FT_READ:\n\n");

	char buffer[100];

	ret = ft_read(0, buffer, sizeof(buffer) - 1);
	if (ret == -1)
		perror("Erreur de ft_read");
	else
	{
		buffer[ret] = '\0';
		printf("Donnees lues: %s\n", buffer);
	}

	ret = ft_read(-1, buffer, sizeof(buffer) - 1);
	if (ret == -1)
		perror("Erreur de ft_read");
	printf("Retour de ft_read (fd invalide): %zd, errno: %d\n", ret, errno);

	return (0);
}
