#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

// ဝင်ရောက်ရန် သတ်မှတ်ထားသော လျှို့ဝှက်နံပါတ် (ဥပမာ - "admin123")
#define APP_PASSWORD "admin123"

// Authentication အတွက် ပုံစံငယ်
// အောင်မြင်ပါက true၊ မအောင်မြင်ပါက false ပြန်ပေးမည်
bool login();

#endif