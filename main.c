#include "get_next_line.h"

// void	f()
// {
// 	system("leaks a.out");
// }
// int main()
// {
// 	int fd = open("txt.txt", O_RDWR | O_CREAT, 0777);
//     int fd1 = open("tocopy.text", O_RDWR | O_CREAT, 0744);
//     int fd2 = open("togetline.text", O_RDWR | O_CREAT, 0744);
//     char str[BUFFER_SIZE];
//     char *s;
//     ssize_t bytes = 1;

//     // while((bytes = read(fd, str, BUFFER_SIZE)) > 0)
//     // {
//     //     write(fd1, str, bytes);
//     // }

//     // while ((s = get_next_line(fd)))
//     // {
//     //     printf("%s", s);
//     //     free(s);
//     // }
//     s = get_next_line(fd);
//     //free(s);
//     printf("%s", s);
// 	//printf("%s", get_next_line(fd));
// 	// while ((str  = get_next_line(fd)))
// 	// {
// 	// 	printf("%s", str);
// 	// 	free(str);
// 	// }
// 	//atexit(f);
// }
// #include "get_next_line_bonus.h"

// // Color codes for test output
// #define GREEN "\033[0;32m"
// #define RED "\033[0;31m"
// #define RESET "\033[0m"

// // Test macros
// #define ASSERT_GE_ZERO(val, msg) \
//     do { \
//         if ((val) < 0) { \
//             printf(RED "FAIL: " msg " is invalid" RESET "\n"); \
//             return 0; \
//         } \
//     } while(0)

// #define ASSERT_EQUAL_STR(actual, expected, msg) \
//     do { \
//         if (strcmp((actual), (expected)) != 0) { \
//             printf(RED "FAIL: %s\n  Expected: '%s'\n  Got:      '%s'" RESET "\n", \
//                    (msg), (expected), (actual)); \
//             free(actual); \
//             return 0; \
//         } \
//     } while(0)

// // Test function to read single file
// int test_single_file()
// {
//     printf("Testing single file reading...\n");
    
//     // Create a test file
//     FILE *test_file = fopen("test_single.txt", "w");
//     fprintf(test_file, "First line\nSecond line\nThird line\n");
//     fclose(test_file);

//     // Open file for reading
//     int fd = open("test_single.txt", O_RDONLY | O_CREAT, 0744);
//     ASSERT_GE_ZERO(fd, "File descriptor");

//     // Read lines
//     char *line1 = get_next_line(fd);
//     ASSERT_EQUAL_STR(line1, "First line\n", "First line content");

//     char *line2 = get_next_line(fd);
//     ASSERT_EQUAL_STR(line2, "Second line\n", "Second line content");

//     char *line3 = get_next_line(fd);
//     ASSERT_EQUAL_STR(line3, "Third line\n", "Third line content");

//     // Check end of file
//     char *line4 = get_next_line(fd);
//     if (line4 != NULL) {
//         printf(RED "FAIL: Expected NULL at end of file" RESET "\n");
//         free(line4);
//         return 0;
//     }

//     close(fd);
//     unlink("test_single.txt");

//     printf(GREEN "Single file test PASSED" RESET "\n");
//     return 1;
// }

// // Test function to read multiple files
// int test_multiple_files()
// {
//     printf("Testing multiple file descriptors...\n");
    
//     // Create test files
//     FILE *file1 = fopen("test_file1.txt", "w");
//     fprintf(file1, "File1 Line1\nFile1 Line2\n");
//     fclose(file1);

//     FILE *file2 = fopen("test_file2.txt", "w");
//     fprintf(file2, "File2 Line1\nFile2 Line2\n");
//     fclose(file2);

//     // Open files
//     int fd1 = open("test_file1.txt", O_RDONLY | O_CREAT, 0744);
//     int fd2 = open("test_file2.txt", O_RDONLY | O_CREAT, 0744);
//     ASSERT_GE_ZERO(fd1, "File 1 descriptor");
//     ASSERT_GE_ZERO(fd2, "File 2 descriptor");

//     // Read alternating lines from different files
//     char *line1_file1 = get_next_line(fd1);
//     ASSERT_EQUAL_STR(line1_file1, "File1 Line1\n", "File1 First line content");

//     char *line1_file2 = get_next_line(fd2);
//     ASSERT_EQUAL_STR(line1_file2, "File2 Line1\n", "File2 First line content");

//     char *line2_file1 = get_next_line(fd1);
//     ASSERT_EQUAL_STR(line2_file1, "File1 Line2\n", "File1 Second line content");

//     char *line2_file2 = get_next_line(fd2);
//     ASSERT_EQUAL_STR(line2_file2, "File2 Line2\n", "File2 Second line content");

//     close(fd1);
//     close(fd2);
    
//     unlink("test_file1.txt");
//     unlink("test_file2.txt");

//     printf(GREEN "Multiple file test PASSED" RESET "\n");
//     return 1;
// }

// // Test function for empty file
// int test_empty_file()
// {
//     printf("Testing empty file...\n");
    
//     // Create an empty file
//     FILE *test_file = fopen("test_empty.txt", "w");
//     fclose(test_file);

//     // Open file for reading
//     int fd = open("test_empty.txt", O_RDONLY | O_CREAT, 0744);
//     ASSERT_GE_ZERO(fd, "Empty file descriptor");

//     // Read from empty file
//     char *line = get_next_line(fd);
//     if (line != NULL) {
//         printf(RED "FAIL: Expected NULL for empty file" RESET "\n");
//         free(line);
//         return 0;
//     }

//     close(fd);
//     unlink("test_empty.txt");

//     printf(GREEN "Empty file test PASSED" RESET "\n");
//     return 1;
// }

// // Test function for large buffer size
// int test_large_buffer()
// {
//     printf("Testing large line reading...\n");
    
//     // Create a file with a long line
//     FILE *test_file = fopen("test_large.txt", "w");
//     fprintf(test_file, "This is a very long line that exceeds the typical buffer size of 42 bytes and will test the ability of get_next_line to handle larger lines correctly.\n");
//     fclose(test_file);

//     // Open file for reading
//     int fd = open("test_large.txt", O_RDONLY | O_CREAT, 0744);
//     ASSERT_GE_ZERO(fd, "Large buffer file descriptor");

//     // Read the long line
//     char *line = get_next_line(fd);
//     ASSERT_EQUAL_STR(line, "This is a very long line that exceeds the typical buffer size of 42 bytes and will test the ability of get_next_line to handle larger lines correctly.\n", "Large line content");

//     close(fd);
//     unlink("test_large.txt");

//     printf(GREEN "Large buffer test PASSED" RESET "\n");
//     return 1;
// }

// int main()
// {
//     int total_tests = 4;
//     int passed_tests = 0;

//     passed_tests += test_single_file();
//     passed_tests += test_multiple_files();
//     passed_tests += test_empty_file();
//     passed_tests += test_large_buffer();

//     printf("\nTest Summary: %d/%d tests passed\n", 
//            passed_tests, total_tests);

//     return passed_tests == total_tests ? 0 : 1;
// }