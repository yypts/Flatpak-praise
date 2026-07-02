# 🟢 Flatpak 任务3：理解 Runtime vs SDK

## 🎯 目标

通过实验感受 Runtime 和 SDK 的差异。

## 📂 文件

```
task3/
├── com.example.checkenv.yml   ← 提供
└── .placeholder               ← 空的，只有清单就够
```

## 📝 你要做的

### Step 1：编译安装

```bash
cd ~/flatpak-projects/task3
flatpak-builder --force-clean build-dir com.example.checkenv.yml
flatpak-builder --user --install build-dir com.example.checkenv.yml
```

### Step 2：运行看看

```bash
flatpak run com.example.checkenv
```

观察输出——**gcc 有没有安装？头文件在不在？**

### Step 3：进入 Runtime 沙箱看看

```bash
flatpak run --command=bash com.example.checkenv

# 在沙箱 bash 里执行：
echo "=== 有没有 gcc？ ==="
gcc --version 2>&1 || echo "没有 gcc"

echo "=== 有没有头文件？ ==="
ls /usr/include/stdio.h 2>&1 || echo "没有头文件"

echo "=== 看看 /usr 有多大 ==="
du -sh /usr 2>/dev/null

exit  # 退出沙箱
```

### Step 4：对比宿主机的环境

```bash
# 在宿主机（你的 Fedora）上执行：
echo "=== 宿主机 gcc ==="
gcc --version | head -1

echo "=== 宿主机 /usr/include ==="
ls /usr/include/stdio.h

echo "=== 宿主机 /usr 有多大 ==="
du -sh /usr 2>/dev/null
```

## ✅ 完成标准

- [ ] Step 2 运行成功
- [ ] 观察到沙箱里 **没有 gcc**
- [ ] 观察到沙箱里 **没有头文件**
- [ ] 对比宿主机和沙箱的 `/usr` 大小差异

## ❓ 完成后回答

1. 沙箱里有 gcc 吗？有头文件吗？
2. 沙箱的 `/usr` 和宿主机的 `/usr` 大小差多少？
3. 思考：为什么 Flatpak 在运行时不带 SDK？