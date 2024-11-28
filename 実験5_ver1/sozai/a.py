import matplotlib.pyplot as plt
import numpy as np
import matplotlib.font_manager as fm

# 日本語対応フォントの設定
font_path = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"  # 日本語対応フォントのパス
font_prop = fm.FontProperties(fname=font_path)

# データ
filters = ["No filter", "Average filter", "Gaussian F", "Median F", "Bilateral filter"]
actual_position = np.array([488.5, -130.0])  # 実位置 (X, Y)
measured_positions = np.array([
    [486.2, -120.1],
    [485.6, -130.3],
    [486.1, -128.6],
    [485.4, -204.3],
    [486.1, -126.9]
])

# 実位置の全体的な距離
actual_distance = np.linalg.norm(actual_position)

# 各フィルタの誤差距離
absolute_errors = np.linalg.norm(measured_positions - actual_position, axis=1)

# 誤差率 [%]
error_rates = (absolute_errors / actual_distance) * 100

# グラフ作成
plt.figure(figsize=(10, 6))
plt.bar(filters, error_rates, alpha=0.7, edgecolor='black')
plt.title("実位置と計測位置の誤差率（フィルタ別）", fontsize=14, fontproperties=font_prop)
plt.xlabel("フィルタの種類", fontsize=12, fontproperties=font_prop)
plt.ylabel("誤差率 [%]", fontsize=12, fontproperties=font_prop)
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()
plt.show()

