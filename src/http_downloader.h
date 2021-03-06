#ifndef __HTTPCDOWNLOADER_H__
#define __HTTPCDOWNLOADER_H__

#include <string>
#include <functional>

typedef struct _progress_info {
	double progress_percentage;  	//96.21%
	std::string remaining_time;		//1MB/s
	std::string download_speed; 	//00:01:54 hh::mm::ss
} progress_info;

typedef std::function<void (const progress_info& progresse)> progress_callback_t;

class http_downloader {
public:
	http_downloader();
	~http_downloader();

public:
	//just for download file, not for webpage. like: https:://gtz.io/gtz_latest.run  note: not thread safe
	int download_file(const std::string& url, const std::string& save_path, progress_callback_t pcb = nullptr);

	double get_download_speed(const std::string& url);

private:
	void progress_callback(void *userdata, double download_speed, double remaining_time, double progress_percentage);

private:
	progress_info progress_info_;
	progress_callback_t progress_callback_;
};

#endif		// __HTTPCLIENT_H__
