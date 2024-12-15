#include <sys/stat.h>

void	put_stat(struct stat *buf)
{
	printf("st_dev: %d\n", buf->st_dev);
	printf("st_ino: %d\n", buf->st_ino);
	printf("st_mode: %d\n", buf->st_mode);
	printf("st_nlink: %d\n", buf->st_nlink);
	printf("st_uid: %d\n", buf->st_uid);
	printf("st_gid: %d\n", buf->st_gid);
	printf("st_rdev: %d\n", buf->st_rdev);
	printf("st_size: %d\n", buf->st_size);
	printf("st_blksize: %d\n", buf->st_blksize);
	printf("st_blocks: %d\n", buf->st_blocks);
	printf("st_atime: %d\n", buf->st_atime);
	printf("st_mtime: %d\n", buf->st_mtime);
	printf("st_ctime: %d\n", buf->st_ctime);
}

int	main(void)
{
	struct stat	buf;

	stat("../cd_opt_test/symboric_1", &buf);
	printf("stat_symboric_1\n");
	put_stat(&buf);
	printf("\n");
	lstat("../cd_opt_test/symboric_1", &buf);
	printf("lstat_symboric_1\n");
	put_stat(&buf);
	printf("\n");
	stat("../cd_opt_test/physical_dir", &buf);
	printf("stat_physical_dir\n");
	put_stat(&buf);
	printf("\n");
	lstat("../cd_opt_test/physical_dir", &buf);
	printf("lstat_physical_dir\n");
	put_stat(&buf);
	return (0);
}
