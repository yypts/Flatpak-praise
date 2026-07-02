# 🟢 Flatpak 任务1：第一个包

## 📂 文件清单

```
hello/               ← 在你的 ~/flatpak-projects/hello/
├── hello.c          ← 源码（提供）
├── com.example.hello.yml  ← 清单文件（提供）
```

## 🎯 你要做的

### Step 1：把文件放到你的机器上

把上面两个文件（`hello.c` 和 `com.example.hello.yml`）复制到：

```bash
~/flatpak-projects/hello/
```

### Step 2：编译构建

```bash
cd ~/flatpak-projects/hello
flatpak-builder --force-clean build-dir com.example.hello.yml
```

如果成功，你会看到一堆编译输出，没有报错。

### Step 3：安装到本地

```bash
flatpak-builder --user --install build-dir com.example.hello.yml
```

### Step 4：运行！

```bash
flatpak run com.example.hello
```

看到打招呼就成功了！🎉

### Step 5：验证它真的是沙箱里跑的

```bash
# 看看能不能访问网络（应该不能）
flatpak run --command=bash com.example.hello
ping baidu.com
# 按 Ctrl+C 退出
exit
```

## ✅ 完成标准

- [ ] Step 2 编译成功，无报错
- [ ] Step 4 运行成功，显示："🐾 小啪的 Flatpak 第一个包！"
- [ ] Step 5 看到 ping 失败（说明沙箱在起作用）

## ❓ 完成之后告诉小啪

1. 编译时有没有报错？
2. 运行起来了吗？
3. 你发现了什么有趣的事情？