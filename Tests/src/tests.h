#pragma once

typedef struct Suite Suite;

Suite* memchr_suite();
Suite* memcmp_suite();
Suite* memcpy_suite();
Suite* memset_suite();
Suite* strncat_suite();
Suite* strchr_suite();
Suite* strncmp_suite();
Suite* strncpy_suite();
Suite* strcspn_suite();
Suite* strerror_suite();
Suite* strlen_suite();
Suite* strpbrk_suite();
Suite* strrchr_suite();
Suite* strstr_suite();
Suite* strtok_suite();

Suite* to_upper_suite();
Suite* to_lower_suite();
Suite* insert_suite();
Suite* trim_suite();

Suite* sscanf_suite();
Suite* sprintf_suite();