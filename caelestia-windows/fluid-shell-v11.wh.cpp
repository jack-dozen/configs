// ==WindhawkMod==
// @id              fluid-shell
// @name            Fluid Shell
// @description     A fluid desktop shell: side bar that replaces the taskbar, plus a launcher with window switcher, calculator and power commands.
// @version         0.1.0
// @author          David Ravelo
// @github          https://github.com/DavidRaveloU
// @include         windhawk.exe
// @compilerOptions -lole32 -lshell32 -luser32 -lgdi32 -ld2d1 -ldwrite -luuid -ladvapi32 -lwindowscodecs -lpropsys -lversion
// @license         MIT
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Fluid Shell

Standalone mod that includes the whole *Fluid Launcher* (a fork of *Spotlight Launcher* by David Ravelo, MIT)
and adds a side bar that replaces the Windows taskbar.

## Side bar (0.1)
* AppBar on the left or right edge: maximized windows stop at the bar.
* Start button, launcher button, the open windows (click = activate or minimize, middle click = close),
  clock, and a power button that opens the launcher in `>` command mode.
* Optional: hides the native Windows taskbar while the bar is enabled.

**If the taskbar ever goes missing:** press **Ctrl + Alt + Shift + T**. If that does not work, press
Ctrl + Shift + Esc, select *Windows Explorer* and choose *Restart*. Disabling the mod also restores it.

## Launcher
Alt + Space (configurable). Type to search apps and Desktop shortcuts. `>` for power / system commands,
`@` for the window switcher, maths expressions for the calculator.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- Hotkey: alt+space
  $name: Keyboard shortcut
  $options:
  - alt+space: Alt + Space
  - ctrl+space: Ctrl + Space
  - ctrl+alt+space: Ctrl + Alt + Space
  - shift+alt+space: Shift + Alt + Space
  - ctrl+shift+space: Ctrl + Shift + Space
- Position: custom
  $name: Position preset
  $description: Presets override the sliders below (Left/Right still use the vertical slider).
  $options:
  - custom: Custom (use the sliders)
  - top: Top edge, centered
  - bottom: Bottom edge, centered (list grows upward)
  - left: Left edge
  - right: Right edge
  - center: Center of the screen
- HorizontalPosition: 50
  $name: Horizontal position (%)
  $description: 0 = left edge, 50 = centered, 100 = right edge.
- VerticalPosition: 30
  $name: Vertical position (%)
  $description: 0 = top edge, 100 = bottom edge.
- EdgeMargin: 12
  $name: Edge margin (DIP)
  $description: Gap to the screen edge when docked. 0 = flush with the edge.
- Placeholder: "Search applications…"
  $name: Search bar placeholder text
  $description: Shown when the bar is empty. Leave empty for the default.
- WindowPrefix: at
  $name: Window switcher prefix
  $description: Type this first to list the open windows (">" is for commands).
  $options:
  - at: "@ (at sign)"
  - hash: "# (hash)"
  - lt: "< (less than)"
  - off: Off
- ConfirmPowerCommands: true
  $name: Ask for a second Enter before Shutdown / Restart / Logout
- Size: small
  $name: Launcher size
  $description: Size of the launcher only. The bar has its own size (BarScale).
  $options:
  - big: Big
  - medium: Medium
  - small: Small
- CornerRadius: 20
  $name: Corner radius (0-36)
  $description: With real-time acrylic on Windows 11 the radius snaps to 0, 4 or 8.
- NotchMode: false
  $name: Notch mode
  $description: Flat edge on the side docked to the screen edge, with concave flares so the bar looks like it grows out of the bezel. Forces edge margin 0 and turns real-time acrylic off. Use together with a Top/Bottom/Left/Right preset.
- DockToScreenEdge: true
  $name: Dock to the real screen edge
  $description: Ignore the taskbar area (useful when the taskbar is hidden or auto-hide).
- ListDirection: auto
  $name: Result list direction
  $options:
  - auto: Auto (upward when the bar is in the lower part of the screen)
  - down: Always downward
  - up: Always upward
- Animation: popup
  $name: Open animation
  $options:
  - popup: Pop up
  - fade: Fade
  - slideBottom: Slide from bottom
  - slideTop: Slide from top
  - slideLeft: Slide from left
  - slideRight: Slide from right
  - none: None
- AnimationBounce: soft
  $name: Animation bounce
  $description: Only the Pop up style overshoots. Slides and the card height settle without bouncing.
  $options:
  - none: None
  - soft: Soft
  - bouncy: Bouncy
- AnimationDuration: 220
  $name: Animation duration (ms)
- AnimationFade: false
  $name: Fade while sliding
  $description: Pop up and Fade always fade.
- SlideDistance: 0
  $name: Slide distance (DIP)
  $description: 0 = start from the screen edge. Otherwise slide this many DIP.
- Borderless: true
  $name: Borderless (no outline, no sheen)
- Shadow: false
  $name: Drop shadow
- Color: midnight
  $name: Color preset
  $options:
  - midnight: Midnight
  - graphite: Graphite
  - black: Black
  - violet: Violet
  - emerald: Emerald
  - teal: Teal
  - rose: Rose
  - crimson: Crimson
  - amber: Amber
  - white: White
  - sky: Sky
  - lavender: Lavender
- CustomBackground: ""
  $name: Custom background color (hex)
  $description: Example #1E1E2E. Leave empty to use the preset. Light/dark text is chosen automatically.
- CustomAccent: ""
  $name: Custom accent color (hex)
  $description: Example #FF6A3D. Leave empty to use the preset.
- Effect: solid
  $name: Background effect
  $options:
  - solid: Solid (simple)
  - acrylic: Acrylic
  - mica: Mica
  - glass: Glass
  - frosted: Frosted
  - aurora: Aurora
- Opacity: 90
  $name: Opacity (70-100)
- BlurAmount: 50
  $name: Blur amount (0-100)
- LiveAcrylic: true
  $name: Real-time acrylic (Acrylic / Glass / Frosted / Aurora)
- MaxResults: 8
  $name: Maximum results (3-12)
- ListMode: expanded
  $name: List mode
  $options:
  - expanded: Expanded (recent + suggestions)
  - compact: Compact (only when typing)
- DetailsKey: ctrl+i
  $name: Details panel key
  $options:
  - ctrl+i: Ctrl + I
  - ctrl+k: Ctrl + K
  - ctrl+space: Ctrl + Space
  - f4: F4
- ScanDesktop: true
  $name: Include Desktop shortcuts and programs
- HideUtilityEntries: true
  $name: Hide uninstallers and documentation
- ReindexMode: auto
  $name: App index updates
  $options:
  - auto: Automatic
  - always: Every time it opens
  - min1: Every 1 minute
  - min3: Every 3 minutes
  - min5: Every 5 minutes
  - min10: Every 10 minutes
- DisableInFullscreen: true
  $name: Disable in fullscreen apps
- CalculatorEnabled: true
  $name: Inline calculator
- CalculatorStyle: both
  $name: Calculator style
  $options:
  - both: Card and inline text
  - hero: Card only
  - ghost: Inline text only
- SoundEnabled: true
  $name: Interface sounds
- SoundVolume: 70
  $name: Sound volume (0-100)
- BarEnabled: true
  $name: Side bar (taskbar replacement)
- BarSide: left
  $name: Bar side
  $options:
  - left: Left
  - right: Right
- BarWidth: 56
  $name: Bar width (DIP, 36-120)
- BarGap: 8
  $name: Gap between the bar and windows (DIP)
- BarClock24h: true
  $name: 24-hour clock in the bar
- DashboardEnabled: true
  $name: Dashboard panel (grows out of the top of the frame)
- DashboardHotkey: ctrlaltd
  $name: Dashboard shortcut
  $options:
  - ctrlaltd: Ctrl + Alt + D
  - altshiftd: Alt + Shift + D
  - winshiftd: Win + Shift + D
- DashboardHotEdge: true
  $name: Open the dashboard by resting the cursor on the top frame
  $description: Only the middle of the top frame counts, with a short delay, never while dragging and never in fullscreen apps.
- HotEdgeDelay: 250
  $name: Hot edge delay (ms)
- FrameEnabled: true
  $name: Screen frame (border around the screen)
  $description: Draws a border with rounded inner corners that merges with the bar. Works best with the Windows taskbar hidden (HideNativeTaskbar).
- FrameThickness: 7
  $name: Frame thickness (DIP, 2-40)
- FrameCornerRadius: 10
  $name: Frame inner corner radius (DIP, 2-36)
  $description: Smaller = less rounded, closer to the square corners of windows. The launcher follows it while the frame is on.
- WindowGap: 8
  $name: Gap between maximized windows and the frame / bar (DIP)
  $description: 0 = windows touch the frame. Only applies while the frame is on.
- BarShowStatus: true
  $name: Show Wi-Fi, volume and battery in the bar
- BarScale: 65
  $name: Bar size (% of the normal size, 40-150)
  $description: Shrinks the whole bar. 65 is roughly two thirds of the previous size.
- BarShowIcons: false
  $name: Show app icons instead of dots
  $description: Dots only by default. Store apps (like Settings) may have no icon in icon mode.
- BarFlushToEdge: true
  $name: Glue the bar to the real screen edge
  $description: Ignores other AppBars / overlays that already reserve that edge.
- BarIgnore: ""
  $name: Hide these apps from the bar
  $description: Process names or title fragments separated by ; or , - for example lively;glazewm
- HideNativeTaskbar: true
  $name: Hide the Windows taskbar while the bar is enabled
  $description: Emergency restore shortcut - Ctrl + Alt + Shift + T. Tip - test the bar first with this turned off.
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <winver.h>
#include <windowsx.h>
#include <shellapi.h>
#include <shobjidl.h>
#include <shlobj.h>
#include <propsys.h>
#include <wincodec.h>
#include <commoncontrols.h>
#include <sddl.h>

// windows.h defines DrawText as a macro (DrawTextW); it must be removed BEFORE d2d1.h
// so that ID2D1RenderTarget::DrawText keeps its name.
#ifdef DrawText
#undef DrawText
#endif

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <xaudio2.h>
#include <audioclient.h>
#include <audiopolicy.h>
#include <endpointvolume.h>
#include <mmdeviceapi.h>

// Implemented by the Fluid Shell module further down.
namespace FluidShell {
bool GetInnerRect(const RECT& monitor, RECT* out);
bool FrameActive();
int FrameRadiusDip();
}  // namespace FluidShell

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <cwctype>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdio>
#include <cwchar>
#include <cstring>

#ifndef LOAD_LIBRARY_SEARCH_SYSTEM32
#define LOAD_LIBRARY_SEARCH_SYSTEM32 0x00000800
#endif

// ===== Inline calculator engine =====
// A small self-contained arithmetic evaluator (tokenizer + recursive-descent parser). It is
// never fed to another interpreter: it only recognises numbers, the four operations, powers,
// percentages, factorials, a fixed set of functions and a few constants, so it is safe to run
// on whatever the user types. Detection is strict (the whole string must parse and look like
// maths) to avoid matching ordinary app names that merely contain numbers or symbols.
namespace Calc {

struct Locale {
    wchar_t decimal = L'.';
    wchar_t group = L',';
    bool grouping = true;
};

inline Locale SystemLocale() {
    Locale l;
    wchar_t buf[8] = {};
    if (GetLocaleInfoW(LOCALE_USER_DEFAULT, LOCALE_SDECIMAL, buf, ARRAYSIZE(buf)) > 1) {
        l.decimal = buf[0];
    }
    int n = GetLocaleInfoW(LOCALE_USER_DEFAULT, LOCALE_STHOUSAND, buf, ARRAYSIZE(buf));
    if (n > 1) {
        l.group = buf[0];
    } else {
        l.grouping = false;
    }
    if (l.group == l.decimal) {
        l.grouping = false;
    }
    return l;
}

enum class Status { NotMath, Ok, Error };

struct Result {
    Status status = Status::NotMath;
    double value = 0.0;
    std::wstring error;
    // When set, the caller shows this text instead of formatting `value` (unit results, base
    // conversions). It is not parseable by the evaluator, so `insertable` holds the plain form.
    std::wstring display;
    std::wstring insertable;
    // The input was just a constant such as "pi" or "ans". App matches take priority over it.
    bool loneConstant = false;
};

// Values supplied by the host: the previous result, so "ans" can be reused.
struct Context {
    bool hasAns = false;
    double ans = 0.0;
};

// A unit: canonical symbol for display, the dimension it belongs to, and the affine transform to
// and from the dimension's base unit (base = value * factor + offset).
struct UnitDef {
    const wchar_t* name;
    const wchar_t* sym;
    int dim;
    double factor;
    double offset;
};

// Dimensions (must match the `dim` field of the table below).
enum {
    DIM_LENGTH = 0,
    DIM_MASS,
    DIM_TIME,
    DIM_DATA,
    DIM_VOLUME,
    DIM_SPEED,
    DIM_AREA,
    DIM_ANGLE,
    DIM_PRESSURE,
    DIM_ENERGY,
    DIM_POWER,
    DIM_TEMP,
};

inline const std::vector<UnitDef>& UnitTable() {
    static const std::vector<UnitDef> t = {
        // ---- length (base: metre) ----
        {L"nm", L"nm", DIM_LENGTH, 1e-9, 0}, {L"um", L"µm", DIM_LENGTH, 1e-6, 0},
        {L"mm", L"mm", DIM_LENGTH, 1e-3, 0}, {L"cm", L"cm", DIM_LENGTH, 1e-2, 0},
        {L"dm", L"dm", DIM_LENGTH, 0.1, 0},  {L"m", L"m", DIM_LENGTH, 1, 0},
        {L"km", L"km", DIM_LENGTH, 1000, 0}, {L"in", L"in", DIM_LENGTH, 0.0254, 0},
        {L"inch", L"in", DIM_LENGTH, 0.0254, 0}, {L"ft", L"ft", DIM_LENGTH, 0.3048, 0},
        {L"foot", L"ft", DIM_LENGTH, 0.3048, 0}, {L"yd", L"yd", DIM_LENGTH, 0.9144, 0},
        {L"yard", L"yd", DIM_LENGTH, 0.9144, 0}, {L"mi", L"mi", DIM_LENGTH, 1609.344, 0},
        {L"mile", L"mi", DIM_LENGTH, 1609.344, 0}, {L"nmi", L"nmi", DIM_LENGTH, 1852, 0},
        // ---- mass (base: kilogram) ----
        {L"mg", L"mg", DIM_MASS, 1e-6, 0}, {L"g", L"g", DIM_MASS, 1e-3, 0},
        {L"kg", L"kg", DIM_MASS, 1, 0},    {L"t", L"t", DIM_MASS, 1000, 0},
        {L"tonne", L"t", DIM_MASS, 1000, 0}, {L"lb", L"lb", DIM_MASS, 0.45359237, 0},
        {L"lbs", L"lb", DIM_MASS, 0.45359237, 0}, {L"pound", L"lb", DIM_MASS, 0.45359237, 0},
        {L"oz", L"oz", DIM_MASS, 0.028349523125, 0}, {L"ounce", L"oz", DIM_MASS, 0.028349523125, 0},
        {L"st", L"st", DIM_MASS, 6.35029318, 0}, {L"stone", L"st", DIM_MASS, 6.35029318, 0},
        // ---- time (base: second) ----
        {L"ns", L"ns", DIM_TIME, 1e-9, 0}, {L"us", L"µs", DIM_TIME, 1e-6, 0},
        {L"ms", L"ms", DIM_TIME, 1e-3, 0}, {L"s", L"s", DIM_TIME, 1, 0},
        {L"sec", L"s", DIM_TIME, 1, 0},    {L"second", L"s", DIM_TIME, 1, 0},
        {L"min", L"min", DIM_TIME, 60, 0}, {L"minute", L"min", DIM_TIME, 60, 0},
        {L"h", L"h", DIM_TIME, 3600, 0},   {L"hr", L"h", DIM_TIME, 3600, 0},
        {L"hour", L"h", DIM_TIME, 3600, 0}, {L"day", L"d", DIM_TIME, 86400, 0},
        {L"week", L"wk", DIM_TIME, 604800, 0}, {L"year", L"yr", DIM_TIME, 31557600, 0},
        // ---- data (base: byte) ----
        {L"bit", L"bit", DIM_DATA, 0.125, 0}, {L"byte", L"B", DIM_DATA, 1, 0},
        {L"kb", L"kB", DIM_DATA, 1000, 0},  {L"mb", L"MB", DIM_DATA, 1e6, 0},
        {L"gb", L"GB", DIM_DATA, 1e9, 0},   {L"tb", L"TB", DIM_DATA, 1e12, 0},
        {L"pb", L"PB", DIM_DATA, 1e15, 0},  {L"kib", L"KiB", DIM_DATA, 1024, 0},
        {L"mib", L"MiB", DIM_DATA, 1048576, 0}, {L"gib", L"GiB", DIM_DATA, 1073741824.0, 0},
        {L"tib", L"TiB", DIM_DATA, 1099511627776.0, 0},
        // ---- volume (base: litre) ----
        {L"ml", L"mL", DIM_VOLUME, 1e-3, 0}, {L"cl", L"cL", DIM_VOLUME, 1e-2, 0},
        {L"dl", L"dL", DIM_VOLUME, 0.1, 0},  {L"l", L"L", DIM_VOLUME, 1, 0},
        {L"liter", L"L", DIM_VOLUME, 1, 0},  {L"litre", L"L", DIM_VOLUME, 1, 0},
        {L"m3", L"m³", DIM_VOLUME, 1000, 0}, {L"gal", L"gal", DIM_VOLUME, 3.785411784, 0},
        {L"gallon", L"gal", DIM_VOLUME, 3.785411784, 0}, {L"qt", L"qt", DIM_VOLUME, 0.946352946, 0},
        {L"pt", L"pt", DIM_VOLUME, 0.473176473, 0}, {L"cup", L"cup", DIM_VOLUME, 0.2365882365, 0},
        {L"floz", L"fl oz", DIM_VOLUME, 0.0295735295625, 0},
        // ---- speed (base: metre/second) ----
        {L"mps", L"m/s", DIM_SPEED, 1, 0}, {L"kph", L"km/h", DIM_SPEED, 1000.0 / 3600, 0},
        {L"kmh", L"km/h", DIM_SPEED, 1000.0 / 3600, 0}, {L"mph", L"mph", DIM_SPEED, 0.44704, 0},
        {L"knot", L"kn", DIM_SPEED, 1000.0 / 3600 * 1.852, 0}, {L"fps", L"ft/s", DIM_SPEED, 0.3048, 0},
        // ---- area (base: square metre) ----
        {L"m2", L"m²", DIM_AREA, 1, 0}, {L"km2", L"km²", DIM_AREA, 1e6, 0},
        {L"cm2", L"cm²", DIM_AREA, 1e-4, 0}, {L"ha", L"ha", DIM_AREA, 10000, 0},
        {L"acre", L"ac", DIM_AREA, 4046.8564224, 0}, {L"sqm", L"m²", DIM_AREA, 1, 0},
        {L"sqft", L"ft²", DIM_AREA, 0.09290304, 0},
        // ---- angle (base: radian) ----
        {L"rad", L"rad", DIM_ANGLE, 1, 0}, {L"deg", L"°", DIM_ANGLE, 3.14159265358979323846 / 180, 0},
        {L"degree", L"°", DIM_ANGLE, 3.14159265358979323846 / 180, 0},
        {L"grad", L"grad", DIM_ANGLE, 3.14159265358979323846 / 200, 0},
        {L"turn", L"turn", DIM_ANGLE, 6.28318530717958647692, 0},
        // ---- pressure (base: pascal) ----
        {L"pa", L"Pa", DIM_PRESSURE, 1, 0}, {L"kpa", L"kPa", DIM_PRESSURE, 1000, 0},
        {L"mpa", L"MPa", DIM_PRESSURE, 1e6, 0}, {L"bar", L"bar", DIM_PRESSURE, 1e5, 0},
        {L"atm", L"atm", DIM_PRESSURE, 101325, 0}, {L"psi", L"psi", DIM_PRESSURE, 6894.757293168, 0},
        {L"mmhg", L"mmHg", DIM_PRESSURE, 133.322387415, 0}, {L"torr", L"Torr", DIM_PRESSURE, 133.322368421, 0},
        // ---- energy (base: joule) ----
        {L"j", L"J", DIM_ENERGY, 1, 0}, {L"kj", L"kJ", DIM_ENERGY, 1000, 0},
        {L"cal", L"cal", DIM_ENERGY, 4.184, 0}, {L"kcal", L"kcal", DIM_ENERGY, 4184, 0},
        {L"wh", L"Wh", DIM_ENERGY, 3600, 0}, {L"kwh", L"kWh", DIM_ENERGY, 3.6e6, 0},
        {L"ev", L"eV", DIM_ENERGY, 1.602176634e-19, 0}, {L"btu", L"BTU", DIM_ENERGY, 1055.05585262, 0},
        // ---- power (base: watt) ----
        {L"w", L"W", DIM_POWER, 1, 0}, {L"kw", L"kW", DIM_POWER, 1000, 0},
        {L"hp", L"hp", DIM_POWER, 745.6998715823, 0},
        // ---- temperature (base: kelvin) ----
        {L"c", L"°C", DIM_TEMP, 1, 273.15}, {L"celsius", L"°C", DIM_TEMP, 1, 273.15},
        {L"f", L"°F", DIM_TEMP, 5.0 / 9, 459.67 * 5.0 / 9}, {L"fahrenheit", L"°F", DIM_TEMP, 5.0 / 9, 459.67 * 5.0 / 9},
        {L"k", L"K", DIM_TEMP, 1, 0}, {L"kelvin", L"K", DIM_TEMP, 1, 0},
    };
    return t;
}

namespace detail {

enum class Tk { Num, Ident, Op, LP, RP, End };

struct Token {
    Tk kind = Tk::End;
    double num = 0.0;
    bool exponent = false;
    std::wstring id;
    wchar_t op = 0;
};

struct Value {
    double v = 0.0;
    bool percent = false;
};

inline bool IsDigit(wchar_t c) { return c >= L'0' && c <= L'9'; }
// Value of a hex/base digit, or -1.
inline int DigitVal(wchar_t c) {
    if (c >= L'0' && c <= L'9') return c - L'0';
    if (c >= L'a' && c <= L'f') return c - L'a' + 10;
    if (c >= L'A' && c <= L'F') return c - L'A' + 10;
    return -1;
}
inline bool IsAlpha(wchar_t c) {
    return (c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z');
}
inline bool IsAlnum(wchar_t c) { return IsAlpha(c) || IsDigit(c); }

inline bool IsConstant(const std::wstring& id, double& out) {
    if (id == L"pi") { out = 3.14159265358979323846; return true; }
    if (id == L"e") { out = 2.71828182845904523536; return true; }
    if (id == L"tau") { out = 6.28318530717958647692; return true; }
    if (id == L"phi") { out = 1.61803398874989484820; return true; }
    if (id == L"\u03c0") { out = 3.14159265358979323846; return true; }
    return false;
}

inline bool IsKeyword(const std::wstring& id) {
    return id == L"mod" || id == L"of";
}

inline bool IsFunction(const std::wstring& id) {
    static const wchar_t* const kFuncs[] = {
        L"sqrt", L"cbrt", L"abs", L"round", L"floor", L"ceil", L"trunc",
        L"sign", L"sin",  L"cos",  L"tan", L"asin",  L"acos", L"atan",
        L"sinh", L"cosh", L"tanh", L"log",   L"ln",   L"log2", L"exp",
        L"fact",
    };
    for (const wchar_t* f : kFuncs) {
        if (id == f) return true;
    }
    return false;
}

inline bool ParseCleanDecimal(const std::wstring& s, double& out) {
    size_t i = 0;
    bool neg = false;
    if (i < s.size() && (s[i] == L'-' || s[i] == L'+')) {
        neg = s[i] == L'-';
        i++;
    }
    double v = 0.0;
    bool any = false;
    while (i < s.size() && IsDigit(s[i])) {
        v = v * 10.0 + (s[i] - L'0');
        any = true;
        i++;
    }
    if (i < s.size() && s[i] == L'.') {
        i++;
        double scale = 0.1;
        while (i < s.size() && IsDigit(s[i])) {
            v += (s[i] - L'0') * scale;
            scale *= 0.1;
            any = true;
            i++;
        }
    }
    if (!any || i != s.size()) return false;
    out = neg ? -v : v;
    return true;
}

inline int CountChar(const std::wstring& s, wchar_t c) {
    int n = 0;
    for (wchar_t x : s) {
        if (x == c) n++;
    }
    return n;
}

// A run of digits/separators is interpreted with the user's decimal and grouping characters.
// A single separator that is not the decimal character is treated as the decimal only when it
// is not a plain thousands group (i.e. not exactly three digits after it).
inline bool ParseNumberLiteral(const std::wstring& run, const Locale& loc, double& out) {
    wchar_t dec = loc.decimal;
    wchar_t alt = (dec == L'.') ? L',' : L'.';

    int decCount = CountChar(run, dec);
    int altCount = CountChar(run, alt);

    bool altIsDecimal = false;
    if (decCount == 0 && altCount > 0) {
        if (altCount >= 2) {
            altIsDecimal = false;
        } else {
            size_t p = run.find(alt);
            size_t before = p;
            size_t after = run.size() - p - 1;
            altIsDecimal = !(after == 3 && before >= 1 && before <= 3);
        }
    }

    std::wstring cleaned;
    bool hasDecimal = false;
    for (wchar_t c : run) {
        if (IsDigit(c)) {
            cleaned += c;
        } else if (c == dec) {
            if (hasDecimal) return false;
            cleaned += L'.';
            hasDecimal = true;
        } else if (c == alt) {
            if (altIsDecimal) {
                if (hasDecimal) return false;
                cleaned += L'.';
                hasDecimal = true;
            }
        } else {
            return false;
        }
    }
    if (cleaned.empty() || cleaned == L".") return false;
    return ParseCleanDecimal(cleaned, out);
}

// Maps typographic/Unicode look-alikes to the ASCII characters the lexer understands, so that
// expressions pasted from documents, messages or web pages (e.g. "5−3" with U+2212, "3×4",
// "6÷2", non-breaking spaces or full-width punctuation) still evaluate.
inline wchar_t NormalizeMathChar(wchar_t c) {
    switch (c) {
        case 0x00A0:  // no-break space
        case 0x2007:  // figure space
        case 0x2008:  // punctuation space
        case 0x2009:  // thin space
        case 0x202F:  // narrow no-break space
        case 0x205F:  // medium mathematical space
        case 0x3000:  // ideographic space
            return L' ';
        case 0x2212:  // minus sign
        case 0x2013:  // en dash
        case 0x2014:  // em dash
        case 0x2011:  // non-breaking hyphen
        case 0xFE63:  // small hyphen-minus
        case 0xFF0D:  // full-width hyphen-minus
        case 0x2216:  // set minus
            return L'-';
        case 0x00D7:  // multiplication sign
        case 0x2217:  // asterisk operator
        case 0x22C5:  // dot operator
        case 0x00B7:  // middle dot
        case 0xFF0A:  // full-width asterisk
            return L'*';
        case 0x00F7:  // division sign
        case 0x2215:  // division slash
        case 0x2044:  // fraction slash
        case 0xFF0F:  // full-width solidus
            return L'/';
        case 0xFF0B:  // full-width plus
            return L'+';
        case 0xFF05:  // full-width percent
            return L'%';
        case 0xFF01:  // full-width exclamation
            return L'!';
        case 0xFF08:  // full-width left parenthesis
            return L'(';
        case 0xFF09:  // full-width right parenthesis
            return L')';
        case 0xFF3E:  // full-width circumflex
            return L'^';
        default:
            return c;
    }
}

struct Lexed {
    std::vector<Token> toks;
    bool ok = true;
    bool mathy = false;       // the input contains something that only makes sense as maths
    bool knownIdents = true;  // every word is a known function, keyword or constant
};

inline Lexed Lex(const std::wstring& in, const Locale& loc, bool hasAns = false) {
    Lexed out;
    bool sawKeyword = false;
    size_t i = 0;
    const size_t n = in.size();
    while (i < n) {
        wchar_t c = NormalizeMathChar(in[i]);
        if (c == L' ' || c == L'\t' || c == L'\r' || c == L'\n') {
            i++;
            continue;
        }
        // Radix-prefixed integers: 0xFF, 0b1010, 0o17 (case-insensitive prefixes/digits).
        if (c == L'0' && i + 1 < n) {
            const wchar_t p = in[i + 1];
            const int base = (p == L'x' || p == L'X')   ? 16
                             : (p == L'b' || p == L'B') ? 2
                             : (p == L'o' || p == L'O') ? 8
                                                        : 0;
            if (base) {
                size_t j = i + 2;
                double val = 0.0;
                bool any = false;
                for (; j < n; ++j) {
                    const int d = DigitVal(in[j]);
                    if (d < 0 || d >= base) break;
                    val = val * base + d;
                    any = true;
                }
                if (any) {
                    Token t;
                    t.kind = Tk::Num;
                    t.num = val;
                    out.toks.push_back(t);
                    out.mathy = true;
                    i = j;
                    continue;
                }
            }
        }
        if (IsDigit(c) || ((c == loc.decimal || c == (loc.decimal == L'.' ? L',' : L'.')) &&
                           i + 1 < n && IsDigit(in[i + 1]))) {
            size_t start = i;
            while (i < n && (IsDigit(in[i]) || in[i] == L'.' || in[i] == L',')) i++;
            std::wstring run = in.substr(start, i - start);
            double val = 0.0;
            if (!ParseNumberLiteral(run, loc, val)) {
                out.ok = false;
                return out;
            }
            bool usedExp = false;
            if (i < n && (in[i] == L'e' || in[i] == L'E')) {
                size_t save = i;
                size_t j = i + 1;
                if (j < n && (in[j] == L'+' || in[j] == L'-')) j++;
                if (j < n && IsDigit(in[j])) {
                    while (j < n && IsDigit(in[j])) j++;
                    std::wstring es = in.substr(save + 1, j - save - 1);
                    double ev = 0.0;
                    if (ParseCleanDecimal(es, ev)) {
                        val *= std::pow(10.0, ev);
                        usedExp = true;
                        i = j;
                    }
                }
            }
            if (usedExp) out.mathy = true;
            Token t;
            t.kind = Tk::Num;
            t.num = val;
            t.exponent = usedExp;
            out.toks.push_back(t);
            continue;
        }
        if (IsAlpha(c)) {
            size_t start = i;
            while (i < n && IsAlnum(in[i])) i++;
            std::wstring id = in.substr(start, i - start);
            for (wchar_t& ch : id) {
                if (ch >= L'A' && ch <= L'Z') ch = (wchar_t)(ch - L'A' + L'a');
            }
            double cval = 0.0;
            bool isKw = IsKeyword(id);
            if (!IsFunction(id) && !isKw && !IsConstant(id, cval) && !(hasAns && id == L"ans")) {
                out.knownIdents = false;
            }
            if (isKw) sawKeyword = true;
            Token t;
            t.kind = Tk::Ident;
            t.id = id;
            out.toks.push_back(t);
            continue;
        }
        if (c == L'+' || c == L'-' || c == L'*' || c == L'/' || c == L'^' || c == L'%' ||
            c == L'!') {
            Token t;
            t.kind = Tk::Op;
            t.op = c;
            out.toks.push_back(t);
            out.mathy = true;
            i++;
            continue;
        }
        if (c == L'(') {
            Token t;
            t.kind = Tk::LP;
            out.toks.push_back(t);
            out.mathy = true;
            i++;
            continue;
        }
        if (c == L')') {
            Token t;
            t.kind = Tk::RP;
            out.toks.push_back(t);
            out.mathy = true;
            i++;
            continue;
        }
        out.ok = false;
        return out;
    }
    // "mod" / "of" only count as maths next to a number ("10 mod 3", "20 of 150"). Alone they are
    // just the start of a name ("Office", "Mod Organizer") and must not show an error card.
    if (sawKeyword) {
        for (const Token& tk : out.toks) {
            if (tk.kind == Tk::Num) { out.mathy = true; break; }
        }
    }
    Token end;
    end.kind = Tk::End;
    out.toks.push_back(end);
    return out;
}

struct Parser {
    const std::vector<Token>& t;
    size_t i = 0;
    bool ok = true;
    std::wstring err;
    Context ctx;

    explicit Parser(const std::vector<Token>& toks, const Context& c = Context{}) : t(toks), ctx(c) {}

    const Token& Cur() const { return t[i]; }
    void Adv() {
        if (i + 1 < t.size()) i++;
    }
    void Fail(const std::wstring& m) {
        if (ok) {
            ok = false;
            err = m;
        }
    }

    double Factorial(double x) {
        if (x < 0.0 || x != std::floor(x) || x > 170.0) {
            Fail(L"factorial is only defined for whole numbers 0-170");
            return 0.0;
        }
        double r = 1.0;
        for (int k = 2; k <= (int)x; k++) r *= k;
        return r;
    }

    double CallFunc(const std::wstring& id, double x) {
        if (id == L"sqrt") { if (x < 0) { Fail(L"square root of a negative number"); return 0; } return std::sqrt(x); }
        if (id == L"cbrt") return std::cbrt(x);
        if (id == L"abs") return std::fabs(x);
        if (id == L"round") return std::round(x);
        if (id == L"floor") return std::floor(x);
        if (id == L"ceil") return std::ceil(x);
        if (id == L"trunc") return std::trunc(x);
        if (id == L"sign") return (double)((x > 0) - (x < 0));
        if (id == L"sin") return std::sin(x);
        if (id == L"cos") return std::cos(x);
        if (id == L"tan") return std::tan(x);
        if (id == L"asin") { if (x < -1 || x > 1) { Fail(L"asin needs a value between -1 and 1"); return 0; } return std::asin(x); }
        if (id == L"acos") { if (x < -1 || x > 1) { Fail(L"acos needs a value between -1 and 1"); return 0; } return std::acos(x); }
        if (id == L"atan") return std::atan(x);
        if (id == L"sinh") return std::sinh(x);
        if (id == L"cosh") return std::cosh(x);
        if (id == L"tanh") return std::tanh(x);
        if (id == L"log") { if (x <= 0) { Fail(L"logarithm needs a positive value"); return 0; } return std::log10(x); }
        if (id == L"ln") { if (x <= 0) { Fail(L"logarithm needs a positive value"); return 0; } return std::log(x); }
        if (id == L"log2") { if (x <= 0) { Fail(L"logarithm needs a positive value"); return 0; } return std::log2(x); }
        if (id == L"exp") return std::exp(x);
        if (id == L"fact") return Factorial(x);
        Fail(L"unknown function");
        return 0.0;
    }

    Value ParsePrimary() {
        Value r;
        const Token& c = Cur();
        if (c.kind == Tk::Num) {
            r.v = c.num;
            Adv();
            return r;
        }
        if (c.kind == Tk::LP) {
            Adv();
            r = ParseExpr();
            if (Cur().kind != Tk::RP) {
                Fail(L"missing closing parenthesis");
                return r;
            }
            Adv();
            return r;
        }
        if (c.kind == Tk::Ident) {
            std::wstring id = c.id;
            Adv();
            if (Cur().kind == Tk::LP) {
                Adv();
                Value a = ParseExpr();
                if (Cur().kind != Tk::RP) {
                    Fail(L"missing closing parenthesis");
                    return r;
                }
                Adv();
                r.v = CallFunc(id, a.v);
                return r;
            }
            double cv = 0.0;
            if (IsConstant(id, cv)) {
                r.v = cv;
                return r;
            }
            if (id == L"ans" && ctx.hasAns) {
                r.v = ctx.ans;
                return r;
            }
            Fail(L"unexpected name");
            return r;
        }
        Fail(L"unexpected symbol");
        return r;
    }

    Value ParsePostfix() {
        Value r = ParsePrimary();
        while (Cur().kind == Tk::Op && (Cur().op == L'%' || Cur().op == L'!')) {
            wchar_t op = Cur().op;
            Adv();
            if (op == L'%') {
                r.v = r.v / 100.0;
                r.percent = true;
            } else {
                r.v = Factorial(r.v);
                r.percent = false;
            }
        }
        return r;
    }

    Value ParsePower() {
        Value base = ParsePostfix();
        if (Cur().kind == Tk::Op && Cur().op == L'^') {
            Adv();
            Value ex = ParseUnary();
            Value r;
            r.v = std::pow(base.v, ex.v);
            r.percent = false;
            return r;
        }
        return base;
    }

    Value ParseUnary() {
        if (Cur().kind == Tk::Op && (Cur().op == L'+' || Cur().op == L'-')) {
            wchar_t op = Cur().op;
            Adv();
            Value u = ParseUnary();
            u.v = (op == L'-') ? -u.v : u.v;
            u.percent = false;
            return u;
        }
        return ParsePower();
    }

    Value ParseTerm() {
        Value left = ParseUnary();
        while (true) {
            const Token& c = Cur();
            bool isMul = c.kind == Tk::Op && (c.op == L'*' || c.op == L'/');
            bool isWord = c.kind == Tk::Ident && IsKeyword(c.id);
            if (!isMul && !isWord) break;
            wchar_t op = isMul ? c.op : 0;
            std::wstring word = isMul ? L"" : c.id;
            Adv();
            Value right = ParseUnary();
            if (isMul) {
                if (op == L'*') {
                    left.v = left.v * right.v;
                } else {
                    if (right.v == 0.0) Fail(L"division by zero");
                    left.v = left.v / right.v;
                }
            } else if (word == L"mod") {
                if (right.v == 0.0) Fail(L"division by zero");
                left.v = std::fmod(left.v, right.v);
            } else {
                left.v = left.v * right.v;  // "20% of 150"
            }
            left.percent = false;
        }
        return left;
    }

    Value ParseExpr() {
        Value left = ParseTerm();
        while (Cur().kind == Tk::Op && (Cur().op == L'+' || Cur().op == L'-')) {
            wchar_t op = Cur().op;
            Adv();
            Value right = ParseTerm();
            // "100 + 15%" adds 15% of the left side; otherwise a percentage is already a fraction.
            double rhs = right.percent ? left.v * right.v : right.v;
            left.v = (op == L'+') ? left.v + rhs : left.v - rhs;
            left.percent = false;
        }
        return left;
    }
};

}  // namespace detail

// Core expression evaluation. `requireMathy` is false for the numeric part of a conversion, where
// a bare number (e.g. "10" in "10 km to miles") must still evaluate.
inline Result EvalCore(const std::wstring& input, const Locale& loc, const Context& ctx,
                       bool requireMathy) {
    Result res;
    detail::Lexed lx = detail::Lex(input, loc, ctx.hasAns);
    if (!lx.ok) return res;
    if (!lx.knownIdents) return res;

    // Count tokens and detect a lone constant. A single well-known constant with two or more
    // letters ("pi", "tau", "phi", "ans") is a calculation by itself, so typing it shows its
    // value. Single letters are excluded so that "e" still searches normally.
    const detail::Token* only = nullptr;
    size_t count = 0;
    for (const auto& t : lx.toks) {
        if (t.kind == detail::Tk::End) continue;
        only = &t;
        ++count;
    }
    if (count == 0) return res;
    bool loneConstant = false;
    if (count == 1 && only->kind == detail::Tk::Ident) {
        double cv = 0.0;
        loneConstant = only->id.size() >= 2 &&
                       (detail::IsConstant(only->id, cv) || (ctx.hasAns && only->id == L"ans"));
    }
    if (requireMathy && !lx.mathy && !loneConstant) return res;

    detail::Parser p(lx.toks, ctx);
    detail::Value v = p.ParseExpr();
    if (!p.ok) {
        res.status = Status::Error;
        res.error = p.err;
        return res;
    }
    if (p.Cur().kind != detail::Tk::End) {
        res.status = Status::Error;
        res.error = L"could not read the whole expression";
        return res;
    }
    if (!std::isfinite(v.v)) {
        res.status = Status::Error;
        res.error = L"result is not a finite number";
        return res;
    }
    res.status = Status::Ok;
    res.value = v.v;
    res.loneConstant = loneConstant;
    return res;
}

inline std::wstring Format(double v, const Locale& loc);  // defined below

// ===== Unit / numeric-base conversions ("<value> to <target>") =====

inline std::vector<std::wstring> SplitWords(const std::wstring& s) {
    std::vector<std::wstring> out;
    std::wstring cur;
    for (wchar_t ch : s) {
        wchar_t c = detail::NormalizeMathChar(ch);
        if (c == L' ' || c == L'\t' || c == L'\r' || c == L'\n') {
            if (!cur.empty()) { out.push_back(cur); cur.clear(); }
        } else {
            if (c >= L'A' && c <= L'Z') c = (wchar_t)(c - L'A' + L'a');
            cur.push_back(c);
        }
    }
    if (!cur.empty()) out.push_back(cur);
    return out;
}

inline std::wstring JoinWords(const std::vector<std::wstring>& w, int a, int b) {
    std::wstring s;
    for (int i = a; i < b; ++i) {
        if (!s.empty()) s += L' ';
        s += w[i];
    }
    return s;
}

inline const UnitDef* FindUnit(const std::wstring& word) {
    const auto& t = UnitTable();
    for (const auto& u : t) {
        if (word == u.name) return &u;
    }
    if (word.size() > 1 && word.back() == L's') {  // plural
        const std::wstring sing = word.substr(0, word.size() - 1);
        for (const auto& u : t) {
            if (sing == u.name) return &u;
        }
    }
    return nullptr;
}

inline int BaseTargetOf(const std::wstring& w) {
    if (w == L"hex" || w == L"hexadecimal") return 16;
    if (w == L"bin" || w == L"binary") return 2;
    if (w == L"oct" || w == L"octal") return 8;
    if (w == L"dec" || w == L"decimal") return 10;
    return 0;
}

// Rank of a byte-based data unit (0 = byte, 1 = kilo, ... 5 = peta). `isBinNamed` is true for the
// explicit binary names (KiB, MiB, ...). "bit" is deliberately excluded: the decimal/binary
// ambiguity is about byte multiples, so bit conversions stay as a single value.
inline bool DataRank(const std::wstring& name, int& rank, bool& isBinNamed) {
    isBinNamed = false;
    if (name == L"byte") { rank = 0; return true; }
    if (name == L"kb") { rank = 1; return true; }
    if (name == L"mb") { rank = 2; return true; }
    if (name == L"gb") { rank = 3; return true; }
    if (name == L"tb") { rank = 4; return true; }
    if (name == L"pb") { rank = 5; return true; }
    if (name == L"kib") { rank = 1; isBinNamed = true; return true; }
    if (name == L"mib") { rank = 2; isBinNamed = true; return true; }
    if (name == L"gib") { rank = 3; isBinNamed = true; return true; }
    if (name == L"tib") { rank = 4; isBinNamed = true; return true; }
    return false;
}

// Values at or beyond 2^64 do not fit the unsigned conversion below (undefined behaviour).
inline bool FitsInBase(double v) { return std::isfinite(v) && std::fabs(v) < 18446744073709551616.0; }

inline std::wstring FormatInBase(double v, int base) {
    if (!FitsInBase(v)) return L"";
    const bool neg = v < 0;
    unsigned long long u = (unsigned long long)(neg ? -v : v);
    static const wchar_t* const kDigits = L"0123456789ABCDEF";
    std::wstring s;
    do {
        s.push_back(kDigits[u % base]);
        u /= base;
    } while (u);
    std::reverse(s.begin(), s.end());
    const wchar_t* prefix = (base == 16) ? L"0x" : (base == 2) ? L"0b" : (base == 8) ? L"0o" : L"";
    return std::wstring(neg ? L"-" : L"") + prefix + s;
}

// Handles "<value> [unit] (to|as) <unit-or-base>". Returns true when it consumed the input (even
// to report an error), false to let normal expression evaluation try instead.
inline bool TryConversion(const std::wstring& input, const Locale& loc, const Context& ctx,
                          Result& out) {
    const std::vector<std::wstring> w = SplitWords(input);
    if (w.size() < 3) return false;
    int k = -1;
    for (size_t idx = 1; idx + 1 < w.size(); ++idx) {
        if (w[idx] == L"to" || w[idx] == L"as") { k = (int)idx; break; }
    }
    if (k < 0 || k + 2 != (int)w.size()) return false;  // right side must be a single word
    const std::wstring target = w[k + 1];

    // Numeric base target.
    if (const int base = BaseTargetOf(target)) {
        const Result l = EvalCore(JoinWords(w, 0, k), loc, ctx, /*requireMathy=*/false);
        if (l.status != Status::Ok) return false;
        if (l.value != std::floor(l.value) || !std::isfinite(l.value)) {
            out.status = Status::Error;
            out.error = L"a base conversion needs a whole number";
            return true;
        }
        if (!FitsInBase(l.value)) {
            out.status = Status::Error;
            out.error = L"the number is too large for a base conversion";
            return true;
        }
        out.status = Status::Ok;
        out.value = l.value;
        out.display = FormatInBase(l.value, base);
        out.insertable = out.display;
        return true;
    }

    // Unit target.
    const UnitDef* dst = FindUnit(target);
    if (!dst) return false;

    const int last = k - 1;
    const UnitDef* src = FindUnit(w[last]);
    std::wstring glueNum;
    if (!src) {
        // "10km" was kept as one word: split it into the number and the unit.
        size_t cut = std::wstring::npos;
        for (size_t p = 0; p < w[last].size(); ++p) {
            if (w[last][p] >= L'a' && w[last][p] <= L'z') { cut = p; break; }
        }
        if (cut != std::wstring::npos && cut > 0) {
            const UnitDef* s2 = FindUnit(w[last].substr(cut));
            if (s2) { src = s2; glueNum = w[last].substr(0, cut); }
        }
    }
    if (!src) return false;

    std::wstring left = JoinWords(w, 0, last);
    if (!glueNum.empty()) {
        if (!left.empty()) left += L' ';
        left += glueNum;
    }
    const Result l = EvalCore(left, loc, ctx, /*requireMathy=*/false);
    if (l.status != Status::Ok) return false;
    if (src->dim != dst->dim) {
        out.status = Status::Error;
        out.error = std::wstring(L"cannot convert ") + src->sym + L" to " + dst->sym;
        return true;
    }

    // Data sizes are ambiguous: "GB" can mean 10^9 (decimal) or 2^30 (binary). Rather than ask the
    // user to choose, show both interpretations of the same target unit. The primary value follows
    // the naming convention the user typed (GiB/MiB -> binary, GB/MB -> decimal).
    if (src->dim == DIM_DATA && dst->dim == DIM_DATA) {
        int rs = 0, rd = 0;
        bool binS = false, binD = false;
        if (DataRank(src->name, rs, binS) && DataRank(dst->name, rd, binD)) {
            const double dres = l.value * std::pow(1000.0, rs - rd);
            const double bres = l.value * std::pow(1024.0, rs - rd);
            const bool primaryBin = binS && binD;
            const double prim = primaryBin ? bres : dres;
            const double other = primaryBin ? dres : bres;
            const std::wstring ps = Format(prim, loc);
            out.status = Status::Ok;
            out.value = prim;
            out.insertable = ps;
            out.display = ps + L" " + dst->sym;
            if (other != prim) {
                out.display += (primaryBin ? L"  (decimal " : L"  (binary ") + Format(other, loc) +
                                L" " + dst->sym + L")";
            }
            return true;
        }
    }

    const double baseVal = l.value * src->factor + src->offset;
    const double conv = (baseVal - dst->offset) / dst->factor;
    out.status = Status::Ok;
    out.value = conv;
    out.display = Format(conv, loc) + L" " + dst->sym;
    out.insertable = Format(conv, loc);
    return true;
}

inline Result Evaluate(const std::wstring& input, const Locale& loc = SystemLocale(),
                       const Context& ctx = Context{}) {
    Result res;
    if (TryConversion(input, loc, ctx, res)) return res;
    return EvalCore(input, loc, ctx, /*requireMathy=*/true);
}

namespace detail {

inline std::wstring GroupInt(const std::wstring& digits, const Locale& loc) {
    bool neg = !digits.empty() && digits[0] == L'-';
    std::wstring d = neg ? digits.substr(1) : digits;
    if (!loc.grouping || d.size() <= 3) return digits;
    std::wstring out;
    int count = 0;
    for (int i = (int)d.size() - 1; i >= 0; --i) {
        out.push_back(d[i]);
        if (++count % 3 == 0 && i > 0) out.push_back(loc.group);
    }
    std::reverse(out.begin(), out.end());
    return neg ? L"-" + out : out;
}

}  // namespace detail

// Formats a value for display: no trailing zeros, thousands grouped and the decimal separator
// taken from the user's Windows locale.
inline std::wstring Format(double v, const Locale& loc) {
    if (!std::isfinite(v)) return L"—";

    bool integral =
        std::fabs(v) < 1e15 && std::fabs(v - std::round(v)) < 1e-9 * std::max(1.0, std::fabs(v));
    if (integral) {
        long long iv = (long long)std::llround(v);
        wchar_t buf[32] = {};
        swprintf(buf, ARRAYSIZE(buf), L"%lld", iv);
        return detail::GroupInt(buf, loc);
    }

    wchar_t buf[64] = {};
    swprintf(buf, ARRAYSIZE(buf), L"%.12g", v);
    std::wstring s = buf;

    std::wstring mant = s;
    std::wstring exp;
    size_t epos = s.find_first_of(L"eE");
    if (epos != std::wstring::npos) {
        mant = s.substr(0, epos);
        exp = s.substr(epos);
    }

    std::wstring ip = mant;
    std::wstring fp;
    size_t dot = mant.find(L'.');
    if (dot != std::wstring::npos) {
        ip = mant.substr(0, dot);
        fp = mant.substr(dot + 1);
    }
    std::wstring out = detail::GroupInt(ip, loc);
    if (!fp.empty()) {
        out += loc.decimal;
        out += fp;
    }
    out += exp;
    return out;
}

}  // namespace Calc

// ===== Design constants (in DIP; they are multiplied by the monitor scale) =====

static const float kMargin = 40.f;     // room for the shadow
static const float kWidth = 700.f;
static const float kBarH = 64.f;
static const float kRowH = 52.f;
static const float kListPad = 8.f;
static const float kEmptyRowH = 56.f;  // message row ("No results")
static float kRadius = 20.f;
static const float kRowRadius = 12.f;
static const float kIconSize = 32.f;
static const float kFooterH = 40.f;    // footer with shortcuts (expanded only)
static const float kSectionH = 26.f;   // section header ("Recent" / "Suggestions")
static const float kHeroH = 84.f;      // calculator result card, reserved above the list
static const float kHistRowH = 34.f;   // compact row for the calculator history

// Details panel (card to the right of the search bar)
static const float kPanelW = 320.f;
// Fixed height shared by the expanded search bar and the details panel; the row count is
// derived from it.
static const float kExpandedMinH = 440.f;
static const float kPanelGap = 12.f;
static const float kPanelPad = 16.f;
static const float kPanelActionsTop = 90.f;  // y of the first action (from the top of the panel)
static const float kActionH = 28.f;
static const float kInfoRowH = 22.f;

// List with an empty search bar (Expanded mode)
static const size_t kMaxRecents = 4;

static const wchar_t kTxtPlaceholder[] = L"Search applications… or type > for power";
static const wchar_t kTxtOpen[] = L"Open";
static const wchar_t kTxtEnterGlyph[] = L"↵";
static const wchar_t kTxtNoResults[] = L"No results";
static const wchar_t kTxtIndexing[] = L"Indexing applications…";
static const wchar_t kTxtRecents[] = L"Recent";
static const wchar_t kTxtSuggestions[] = L"Suggestions";
static const wchar_t kTxtActions[] = L"Actions";
static const wchar_t kTxtInfo[] = L"Information";
static const wchar_t kTxtDetails[] = L"Details";
static const wchar_t kTxtReindex[] = L"Reindex";
static const wchar_t* const kReindexKeys[2] = {L"Ctrl", L"R"};
static const wchar_t kTxtTypeApp[] = L"Application";
static const wchar_t kTxtTypeStore[] = L"Store app";
static const wchar_t kTxtTypeDesktop[] = L"Desktop";
static const wchar_t kTxtTypeCommand[] = L"System";
static const wchar_t kTxtConfirm[] = L"Enter to confirm";
static const wchar_t kTxtCalcCopy[] = L"Copy result";
static const wchar_t kTxtCalcCopied[] = L"Copied";
static const wchar_t kTxtCalcAdd[] = L"Add to operation";
static const wchar_t kTxtCalcEdit[] = L"Edit";
static const wchar_t kTxtCalcDelete[] = L"Delete";
static const wchar_t kTxtCalcClear[] = L"Clear history";
static const wchar_t kTxtCalcHistory[] = L"History";

static const UINT WM_APP_INDEX = WM_APP + 1;
static const UINT WM_APP_ICON = WM_APP + 2;
static const UINT WM_APP_INDEX_DONE = WM_APP + 3;
static const UINT WM_APP_SETTINGS = WM_APP + 4;
static const UINT WM_APP_MENU_CHANGED = WM_APP + 5;  // the watcher detected changes in the Start menu

// Start menu reindexing
static const double kAutoSafetyRescanSec = 600.0;  // fallback in Automatic mode (MSIX apps)
static const DWORD kWatchDebounceMs = 1500;        // wait for the installer to finish

static const double kPi = 3.14159265358979323846;

static const UINT_PTR TIMER_FRAME = 1;
static const UINT_PTR TIMER_BLINK = 2;
static const UINT_PTR TIMER_COPY = 3;  // clears the calculator "Copied" flash
static const UINT_PTR TIMER_CALC = 4;  // debounce for calculator evaluation
static const UINT_PTR TIMER_CONFIRM = 5;  // expires the "press Enter again" state of a power command
static const int HOTKEY_ID = 1;

// ===== Types =====

enum class ReindexMode { Auto, Always, Interval };
enum class ListMode { Compact, Expanded };
enum class DetailsKey { CtrlI, CtrlK, CtrlSpace, F4 };
enum class BgEffect { Acrylic, Mica, Glass, Frosted, Aurora, Solid };
enum class CalcStyle { Hero, Ghost, Both };
enum class AnimStyle { None, Fade, Popup, SlideBottom, SlideTop, SlideLeft, SlideRight };
enum class PosPreset { Custom, Top, Bottom, Left, Right, Center };
enum class ListDir { Auto, Down, Up };

struct LauncherSettings {
    ListMode listMode = ListMode::Expanded;
    DetailsKey detailsKey = DetailsKey::CtrlI;
    ReindexMode reindexMode = ReindexMode::Auto;
    double reindexIntervalSec = 0;  // only with ReindexMode::Interval
    UINT hotkeyMods = MOD_ALT;
    UINT hotkeyVk = VK_SPACE;
    int verticalPct = 30;
    int maxRows = 8;                 // cap on how many results the search returns
    int opacityPct = 90;
    BgEffect effect = BgEffect::Acrylic;
    int blurPct = 50;     // 0..100 -> multiplies the effect's base blur (50 = x1)
    bool liveAcrylic = true;  // DWM acrylic in real time (Acrylic / Frosted / Aurora)
    int colorIdx = 0;     // index in kColors
    bool hideUtility = true;
    bool disableFullscreen = true;  // ignore the shortcut while a fullscreen window is focused
    bool calculatorEnabled = true;
    CalcStyle calcStyle = CalcStyle::Both;
    bool sounds = true;      // soft interface sounds (open, details panel, typing)
    int soundVolume = 70;    // 0..100
    // --- Fluid Launcher additions ---
    bool borderless = true;
    bool shadow = false;
    std::wstring customBg;      // "#RRGGBB" or empty
    std::wstring customAccent;  // "#RRGGBB" or empty
    AnimStyle anim = AnimStyle::Popup;
    int animMs = 220;
    bool animFade = false;
    int slideDist = 0;          // DIP; 0 = from the screen edge
    PosPreset preset = PosPreset::Custom;
    int horizPct = 50;
    int edgeMargin = 12;        // DIP
    ListDir listDir = ListDir::Auto;
    bool scanDesktop = true;
    int cornerRadius = 20;
    bool notch = false;
    bool dockScreenEdge = true;
    double uiSize = 1.0;  // 1.0 big, medium / small shrink the whole UI
    double bounceZeta = 0.72;  // spring damping ratio of the Pop up animation
    bool confirmPower = true;
    std::wstring placeholder;
    wchar_t winPrefix = L'@';  // 0 = window switcher off
};

struct AppEntry {
    std::wstring name;
    std::wstring folded;  // same length as name (folded 1:1)
    std::wstring id;      // parsing name relative to AppsFolder
    std::wstring usageKey;
    bool desktop = false;
    bool isCmd = false;       // power command entry (shown only after ">")
    bool isWin = false;       // open window entry (shown only after the window prefix)
    uintptr_t winHandle = 0;
    std::wstring sub;         // process name for windows
    int cmdId = -1;
    std::wstring alias;       // extra search words for commands (lowercase, space separated)
    int uses = 0;
    int lastUsed = 0;  // seconds since 2020-01-01 (0 = never); see NowStamp()
    int iconW = 0;
    int iconH = 0;
    std::vector<uint32_t> iconPx;  // BGRA premultiplied
    ID2D1Bitmap* bmp = nullptr;
};

struct SearchResult {
    int app = 0;
    int score = 0;
    int section = 0;  // 0 = no section (search), 1 = Recent, 2 = Suggestions
    IDWriteTextLayout* layout = nullptr;
};

// Technical data about an app for the details panel (computed on demand and cached)
struct InfoRow {
    std::wstring label;
    std::wstring value;
    bool middle = false;  // truncate in the middle (paths, identifiers)
};

struct AppDetails {
    bool packaged = false;   // Store app (MSIX)
    bool canFile = false;    // a real program file exists (open location, copy path)
    bool canShell = false;   // this 32-bit process can reach the path (elevate, properties)
    bool isExe = false;
    std::wstring target;     // program path (desktop apps)
    std::wstring args;       // shortcut arguments (kept for elevation)
    std::vector<InfoRow> rows;
};

enum ActionId { ACT_OPEN, ACT_ADMIN, ACT_LOCATION, ACT_COPYPATH, ACT_PROPS, ACT_FORGET };

struct ActionDef {
    int id;
    const wchar_t* label;
    const wchar_t* keys;
};

static const ActionDef kActions[] = {
    {ACT_OPEN, L"Open", L"↵"},
    {ACT_ADMIN, L"Run as administrator", L"Ctrl+Shift+↵"},
    {ACT_LOCATION, L"Open file location", L"Ctrl+↵"},
    {ACT_COPYPATH, L"Copy path", L"Ctrl+Shift+C"},
    {ACT_PROPS, L"Properties", L"Ctrl+P"},
    {ACT_FORGET, L"Remove from recents", L"Ctrl+Shift+R"},
};

struct ThemePalette {
    D2D1_COLOR_F bg;
    D2D1_COLOR_F border;
    D2D1_COLOR_F text;
    D2D1_COLOR_F textDim;
    D2D1_COLOR_F selection;
    D2D1_COLOR_F separator;
    D2D1_COLOR_F keycap;
    D2D1_COLOR_F match;
    D2D1_COLOR_F caretSel;
    D2D1_COLOR_F accent;   // main accent (selection, highlighted letters, Aurora gradient)
    D2D1_COLOR_F accent2;  // second color of the Aurora gradient
    bool light;
    float shadowAlpha;
};

// Available colors: base background, accent and second accent (RGB 0..1).
struct ColorDef {
    const wchar_t* id;
    bool light;
    float bg[3];
    float acc[3];
    float acc2[3];
};

static const ColorDef kColors[] = {
    {L"midnight", false, {0.075f, 0.090f, 0.125f}, {0.30f, 0.55f, 1.00f}, {0.55f, 0.35f, 1.00f}},
    {L"graphite", false, {0.105f, 0.105f, 0.120f}, {0.35f, 0.62f, 1.00f}, {0.65f, 0.45f, 1.00f}},
    {L"black",    false, {0.020f, 0.020f, 0.025f}, {0.45f, 0.70f, 1.00f}, {0.80f, 0.45f, 1.00f}},
    {L"violet",   false, {0.105f, 0.075f, 0.170f}, {0.66f, 0.45f, 1.00f}, {1.00f, 0.45f, 0.75f}},
    {L"emerald",  false, {0.050f, 0.120f, 0.095f}, {0.20f, 0.82f, 0.55f}, {0.25f, 0.75f, 0.95f}},
    {L"teal",     false, {0.045f, 0.110f, 0.130f}, {0.15f, 0.78f, 0.85f}, {0.35f, 0.55f, 1.00f}},
    {L"rose",     false, {0.160f, 0.075f, 0.110f}, {1.00f, 0.40f, 0.62f}, {1.00f, 0.62f, 0.35f}},
    {L"crimson",  false, {0.155f, 0.060f, 0.070f}, {1.00f, 0.35f, 0.38f}, {1.00f, 0.60f, 0.30f}},
    {L"amber",    false, {0.150f, 0.105f, 0.050f}, {1.00f, 0.66f, 0.20f}, {1.00f, 0.40f, 0.35f}},
    {L"white",    true,  {0.975f, 0.975f, 0.980f}, {0.16f, 0.43f, 0.96f}, {0.55f, 0.35f, 0.95f}},
    {L"sky",      true,  {0.915f, 0.955f, 0.995f}, {0.10f, 0.50f, 0.95f}, {0.20f, 0.75f, 0.90f}},
    {L"lavender", true,  {0.945f, 0.930f, 0.985f}, {0.50f, 0.32f, 0.90f}, {0.90f, 0.40f, 0.70f}},
};

struct RawApp {
    std::wstring name;
    std::wstring id;
    bool desktop = false;  // a file on the Desktop (id is the full path)
};

struct IndexResult {
    UINT gen;
    std::vector<RawApp> apps;
};

struct IconResult {
    UINT gen;
    size_t index;
    int w;
    int h;
    std::vector<uint32_t> px;
};

struct IndexJob {
    HWND hwnd;
    UINT gen;
    bool hideUtility;
    bool scanDesktop = true;
    std::unordered_set<std::wstring> haveIcons;
};

enum class Vis { Hidden, Showing, Shown, Hiding };

// ===== Global state (only touched from the UI thread, except where noted) =====

static LauncherSettings g_cfg;
static HWND g_hwnd = nullptr;
static HANDLE g_uiThread = nullptr;
static DWORD g_uiThreadId = 0;

static Vis g_vis = Vis::Hidden;
static double g_visStart = 0;
static double g_shownAt = 0;
static double g_alpha = 0;
static double g_offY = 0;
static double g_offX = 0;
static double g_animK = 1.0;    // animation progress: 0 = fully shown, 1 = hidden (spring state)
static double g_animV = 0.0;
static double g_curHV = 0.0;    // velocity of the card height spring
static double g_detailV = 0.0;  // velocity of the details panel spring
static bool g_clipInner = false;
static RECT g_clipRect = {};
static double g_animFromX = 0;
static double g_animFromY = 0;
static double g_animFromScale = 1.0;
static double g_animScale = 1.0;
static bool g_animFadeOn = true;
static double g_lastFrame = 0;
static bool g_frameTimerOn = false;
static bool g_dirty = false;

static double g_scale = 1.0;
static int g_bmpW = 0;
static int g_bmpH = 0;
static HDC g_memDC = nullptr;
static HBITMAP g_dib = nullptr;
static HGDIOBJ g_oldBmp = nullptr;
static int g_winX = 0;
static int g_winY = 0;
// Vertical placement (screen px). g_anchorTop is where the top of the search bar would sit
// without any limit; the card is kept inside the work area [g_workTop, g_workBottom].
static double g_anchorTop = 0;
static double g_anchorBottom = 0;  // bottom of the card when the list grows upward
static bool g_flip = false;        // bar at the bottom, list grows upward
static double g_hAlign = 0.5;      // 0 = block hugs the left edge, 1 = right edge
static int g_hPct = 50;
static int g_vPct = 30;
static bool g_flatTop = false;     // notch mode: which sides are flat (glued to the screen edge)
static bool g_flatBottom = false;
static bool g_flatLeft = false;
static bool g_flatRight = false;
static HWND g_prevFg = nullptr;    // window that had the focus before the launcher opened
static double g_workTop = 0;
static double g_workBottom = 0;

static ID2D1Factory* g_d2d = nullptr;
static IDWriteFactory* g_dw = nullptr;
static ID2D1DCRenderTarget* g_rt = nullptr;
static ID2D1SolidColorBrush* g_brush = nullptr;
static ID2D1SolidColorBrush* g_matchBrush = nullptr;
static ID2D1StrokeStyle* g_roundStroke = nullptr;
static ID2D1LinearGradientBrush* g_gradBrush = nullptr;  // subtle sheen at the top of the cards
static ID2D1LinearGradientBrush* g_glow1 = nullptr;      // Aurora effect gradient (accent 1)
static ID2D1LinearGradientBrush* g_glow2 = nullptr;      // Aurora effect gradient (accent 2)
static IDWriteTextFormat* g_fmtInput = nullptr;
static IDWriteTextFormat* g_fmtTitle = nullptr;
static IDWriteTextFormat* g_fmtHint = nullptr;
static IDWriteTextFormat* g_fmtKey = nullptr;
static IDWriteTextFormat* g_fmtEmpty = nullptr;
static IDWriteTextFormat* g_fmtSection = nullptr;     // "Recent" / "Actions" headers
static IDWriteTextFormat* g_fmtPanelTitle = nullptr;  // app name in the panel
static IDWriteTextFormat* g_fmtPanelSub = nullptr;    // panel subtitle
static IDWriteTextFormat* g_fmtPanelRow = nullptr;    // panel rows
static IDWriteInlineObject* g_ellipsis = nullptr;
static IDWriteInlineObject* g_ellipsisSm = nullptr;
static ThemePalette g_pal;

// Software acrylic: downscaled and blurred desktop capture (BGRA premultiplied, opaque)
static std::vector<uint32_t> g_backPx;
static int g_backW = 0;
static int g_backH = 0;
static ID2D1Bitmap* g_backBmp = nullptr;          // g_backPx as a D2D bitmap (created when drawing)
static ID2D1BitmapBrush* g_backBrush = nullptr;   // brush in surface coordinates
static ID2D1Bitmap* g_noiseBmp = nullptr;         // grain tile
static ID2D1BitmapBrush* g_noiseBrush = nullptr;
static double g_lastHide = -1e9;                  // last time the window was hidden

static std::vector<AppEntry> g_apps;
static std::vector<SearchResult> g_results;
static std::vector<float> g_rowOff;  // y (DIP) of each row relative to the top of the list, n+1 entries
static int g_headerCount = 0;        // section headers present (only with the search bar empty)
static std::vector<std::wstring> g_tokens;
static std::wstring g_text;
static int g_caret = 0;
static int g_anchor = 0;
static float g_inputScroll = 0;
static bool g_caretOn = true;

static int g_sel = 0;
static double g_selPos = 0;
static double g_selTarget = 0;
static double g_scrollPos = 0;
static double g_scrollTarget = 0;
static bool g_kbScroll = false;  // the scroll came from the keyboard (pixel-exact, partial rows)
static double g_curH = kBarH;
static double g_targetH = kBarH;
static POINT g_lastMouse = {-1, -1};

// Details panel
static bool g_detailsOpen = false;
static double g_detailPos = 0;     // 0..1, animated
static double g_detailTarget = 0;
static int g_hoverAction = -1;     // id of the action under the mouse, or -1
static bool g_hoverReindex = false;  // the mouse is over the footer reindex button
static std::wstring g_panelAppId;  // last app shown in the panel (for the fade-out)
static std::unordered_map<std::wstring, AppDetails> g_detailsCache;

static UINT g_gen = 0;
static bool g_indexing = false;
static bool g_indexedOnce = false;
static double g_lastIndexAt = -1e9;
static bool g_menuDirty = true;  // the Start menu changed since the last reindex (UI thread)

// Inline calculator (see namespace Calc): the result for the current text, its formatted form
// (for the card, the inline text and the clipboard) and when it was last copied (for the flash).
static Calc::Result g_calc;
static std::wstring g_calcDisplay;
static bool g_calcActive = false;
static double g_copiedAt = -1e9;

// Last committed result, exposed to expressions as "ans".
static double g_calcAns = 0.0;
static bool g_calcHasAns = false;

// Calculator history: the last few calculations the user chose to keep (by pressing Enter).
// Newest first; when it is full the oldest entry is dropped.
struct CalcHistoryItem {
    std::wstring expr;    // what the user typed
    std::wstring resFmt;  // the formatted result (shown in the row)
    std::wstring insVal;  // what "Add to operation" inserts (plain number for unit results)
};
static std::vector<CalcHistoryItem> g_calcHist;
static int g_calcHistSel = -1;  // -1 = current result, otherwise the highlighted history row
static double g_histScroll = 0;  // scroll offset (DIP) of the history list
static bool g_calcPending = false;

// Start menu watcher
static HANDLE g_watchThread = nullptr;
static HANDLE g_watchStop = nullptr;

// ===== General utilities =====

static double NowSec() {
    static LARGE_INTEGER freq = [] {
        LARGE_INTEGER f;
        QueryPerformanceFrequency(&f);
        return f;
    }();
    LARGE_INTEGER c;
    QueryPerformanceCounter(&c);
    return (double)c.QuadPart / (double)freq.QuadPart;
}

static float Sc(float v) {
    return v * (float)g_scale;
}

// Compact timestamp (fits in a Wh_SetIntValue int): seconds since 2020-01-01 UTC.
static const ULONGLONG kEpoch2020 = 132223104000000000ULL;  // 2020-01-01 as FILETIME

static int NowStamp() {
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    ULARGE_INTEGER u;
    u.LowPart = ft.dwLowDateTime;
    u.HighPart = ft.dwHighDateTime;
    if (u.QuadPart <= kEpoch2020) return 1;
    return (int)((u.QuadPart - kEpoch2020) / 10000000ULL);
}

static std::wstring FormatFileTime(const FILETIME& utc) {
    FILETIME local;
    SYSTEMTIME st;
    if (!FileTimeToLocalFileTime(&utc, &local) || !FileTimeToSystemTime(&local, &st)) return L"";
    wchar_t d[64] = {};
    wchar_t t[64] = {};
    GetDateFormatW(LOCALE_USER_DEFAULT, DATE_SHORTDATE, &st, nullptr, d, 64);
    GetTimeFormatW(LOCALE_USER_DEFAULT, TIME_NOSECONDS, &st, nullptr, t, 64);
    return std::wstring(d) + L" " + t;
}

static std::wstring FormatStamp(int stamp) {
    ULARGE_INTEGER u;
    u.QuadPart = kEpoch2020 + (ULONGLONG)stamp * 10000000ULL;
    FILETIME ft;
    ft.dwLowDateTime = u.LowPart;
    ft.dwHighDateTime = u.HighPart;
    return FormatFileTime(ft);
}

static double EaseOutCubic(double p) {
    double q = 1.0 - p;
    return 1.0 - q * q * q;
}

// Damped spring towards `target`. zeta < 1 overshoots a little, 1 = critically damped (no overshoot).
// `settle` is roughly the time to come to rest, in seconds. Returns true while still moving.
static bool SpringTo(double& x, double& v, double target, double zeta, double settle, double dt, double epsX,
                     double epsV) {
    if (settle < 0.02) {  // animation switched off
        x = target;
        v = 0.0;
        return false;
    }
    const double w0 = 4.0 / (std::max(0.2, zeta) * settle);
    double left = dt;
    while (left > 0.0) {
        const double h = std::min(left, 0.004);  // small steps keep the integration stable
        const double a = -w0 * w0 * (x - target) - 2.0 * zeta * w0 * v;
        v += a * h;
        x += v * h;
        left -= h;
    }
    if (std::fabs(x - target) < epsX && std::fabs(v) < epsV) {
        x = target;
        v = 0.0;
        return false;
    }
    return true;
}

// Slight overshoot, used by the "Pop up" animation.
static double EaseOutBack(double p) {
    const double c1 = 1.70158;
    const double c3 = c1 + 1.0;
    const double q = p - 1.0;
    return 1.0 + c3 * q * q * q + c1 * q * q;
}

// Exponential smoothing towards the target. Returns true while it is still moving.
static bool Smooth(double& cur, double target, double rate, double dt, double eps) {
    if (cur == target) {
        return false;
    }
    cur += (target - cur) * (1.0 - std::exp(-rate * dt));
    if (std::fabs(target - cur) < eps) {
        cur = target;
        return false;
    }
    return true;
}

template <class T>
static void SafeRelease(T*& p) {
    if (p) {
        p->Release();
        p = nullptr;
    }
}

// Fold a character: lowercase and accent-free (á -> a, ñ -> n). Always 1 char -> 1 char.
static wchar_t FoldChar(wchar_t c) {
    if (c < 0x80) {
        return (c >= L'A' && c <= L'Z') ? (wchar_t)(c + 32) : c;
    }
    wchar_t out[4] = {};
    int n = FoldStringW(MAP_COMPOSITE, &c, 1, out, 4);
    wchar_t base = (n > 0 && out[0]) ? out[0] : c;
    return (wchar_t)(UINT_PTR)CharLowerW((LPWSTR)(UINT_PTR)base);
}

static std::wstring FoldString(const std::wstring& s) {
    std::wstring r(s.size(), L' ');
    for (size_t i = 0; i < s.size(); ++i) {
        r[i] = FoldChar(s[i]);
    }
    return r;
}

static std::wstring GetStringSetting(const wchar_t* name) {
    PCWSTR s = Wh_GetStringSetting(name);  // never returns NULL
    std::wstring r = s;
    Wh_FreeStringSetting(s);
    return r;
}

static void LoadSettings() {
    LauncherSettings c;
    std::wstring hk = GetStringSetting(L"Hotkey");
    UINT mods = 0;
    if (hk == L"alt+space") {
        mods = MOD_ALT;
    } else if (hk == L"ctrl+space") {
        mods = MOD_CONTROL;
    } else if (hk == L"ctrl+alt+space") {
        mods = MOD_CONTROL | MOD_ALT;
    } else if (hk == L"shift+alt+space") {
        mods = MOD_SHIFT | MOD_ALT;
    } else if (hk == L"ctrl+shift+space") {
        mods = MOD_CONTROL | MOD_SHIFT;
    } else {
        mods = MOD_ALT;
    }
    c.hotkeyMods = mods;
    c.hotkeyVk = VK_SPACE;

    c.verticalPct = std::clamp(Wh_GetIntSetting(L"VerticalPosition"), 0, 100);
    c.maxRows = std::clamp(Wh_GetIntSetting(L"MaxResults"), 3, 12);
    c.opacityPct = std::clamp(Wh_GetIntSetting(L"Opacity"), 70, 100);
    {
        std::wstring ef = GetStringSetting(L"Effect");
        c.effect = (ef == L"mica")      ? BgEffect::Mica
                   : (ef == L"glass")   ? BgEffect::Glass
                   : (ef == L"frosted") ? BgEffect::Frosted
                   : (ef == L"aurora")  ? BgEffect::Aurora
                   : (ef == L"solid")   ? BgEffect::Solid
                                        : BgEffect::Acrylic;
    }
    c.blurPct = std::clamp(Wh_GetIntSetting(L"BlurAmount"), 0, 100);
    c.liveAcrylic = Wh_GetIntSetting(L"LiveAcrylic") != 0;

    {
        std::wstring col = GetStringSetting(L"Color");
        c.colorIdx = 0;
        for (int i = 0; i < (int)(sizeof(kColors) / sizeof(kColors[0])); ++i) {
            if (col == kColors[i].id) {
                c.colorIdx = i;
                break;
            }
        }
    }
    c.hideUtility = Wh_GetIntSetting(L"HideUtilityEntries") != 0;
    c.disableFullscreen = Wh_GetIntSetting(L"DisableInFullscreen") != 0;

    std::wstring rm = GetStringSetting(L"ReindexMode");
    if (rm == L"always") {
        c.reindexMode = ReindexMode::Always;
    } else if (rm == L"min1" || rm == L"min3" || rm == L"min5" || rm == L"min10") {
        c.reindexMode = ReindexMode::Interval;
        c.reindexIntervalSec = (double)_wtoi(rm.c_str() + 3) * 60.0;  // "min3" -> 3
    } else {
        c.reindexMode = ReindexMode::Auto;  // default (and if the value is not recognized)
    }

    std::wstring lm = GetStringSetting(L"ListMode");
    c.listMode = (lm == L"compact") ? ListMode::Compact : ListMode::Expanded;

    std::wstring dk = GetStringSetting(L"DetailsKey");
    c.detailsKey = (dk == L"ctrl+k")       ? DetailsKey::CtrlK
                   : (dk == L"ctrl+space") ? DetailsKey::CtrlSpace
                   : (dk == L"f4")         ? DetailsKey::F4
                                           : DetailsKey::CtrlI;
    // If the global shortcut is Ctrl+Space, that shortcut would never reach the window: use Ctrl+I.
    if (c.detailsKey == DetailsKey::CtrlSpace && c.hotkeyMods == MOD_CONTROL) {
        c.detailsKey = DetailsKey::CtrlI;
    }

    c.calculatorEnabled = Wh_GetIntSetting(L"CalculatorEnabled") != 0;
    {
        std::wstring cs = GetStringSetting(L"CalculatorStyle");
        c.calcStyle = (cs == L"hero")  ? CalcStyle::Hero
                      : (cs == L"ghost") ? CalcStyle::Ghost
                                         : CalcStyle::Both;
    }

    c.sounds = Wh_GetIntSetting(L"SoundEnabled") != 0;
    c.soundVolume = std::clamp(Wh_GetIntSetting(L"SoundVolume"), 0, 100);

    c.borderless = Wh_GetIntSetting(L"Borderless") != 0;
    c.shadow = Wh_GetIntSetting(L"Shadow") != 0;
    c.customBg = GetStringSetting(L"CustomBackground");
    c.customAccent = GetStringSetting(L"CustomAccent");
    {
        std::wstring an = GetStringSetting(L"Animation");
        c.anim = (an == L"none")          ? AnimStyle::None
                 : (an == L"fade")        ? AnimStyle::Fade
                 : (an == L"slideBottom") ? AnimStyle::SlideBottom
                 : (an == L"slideTop")    ? AnimStyle::SlideTop
                 : (an == L"slideLeft")   ? AnimStyle::SlideLeft
                 : (an == L"slideRight")  ? AnimStyle::SlideRight
                                          : AnimStyle::Popup;
    }
    c.animMs = std::clamp(Wh_GetIntSetting(L"AnimationDuration"), 0, 2000);
    {
        std::wstring bn = GetStringSetting(L"AnimationBounce");
        c.bounceZeta = (bn == L"none") ? 1.0 : (bn == L"bouncy") ? 0.5 : 0.72;
    }
    c.animFade = Wh_GetIntSetting(L"AnimationFade") != 0;
    c.slideDist = std::clamp(Wh_GetIntSetting(L"SlideDistance"), 0, 4000);
    {
        std::wstring ps = GetStringSetting(L"Position");
        c.preset = (ps == L"top")      ? PosPreset::Top
                   : (ps == L"bottom") ? PosPreset::Bottom
                   : (ps == L"left")   ? PosPreset::Left
                   : (ps == L"right")  ? PosPreset::Right
                   : (ps == L"center") ? PosPreset::Center
                                       : PosPreset::Custom;
        std::wstring ld = GetStringSetting(L"ListDirection");
        c.listDir = (ld == L"up") ? ListDir::Up : (ld == L"down") ? ListDir::Down : ListDir::Auto;
    }
    c.horizPct = std::clamp(Wh_GetIntSetting(L"HorizontalPosition"), 0, 100);
    c.edgeMargin = std::clamp(Wh_GetIntSetting(L"EdgeMargin"), 0, 200);
    c.scanDesktop = Wh_GetIntSetting(L"ScanDesktop") != 0;
    c.cornerRadius = std::clamp(Wh_GetIntSetting(L"CornerRadius"), 0, 36);
    c.notch = Wh_GetIntSetting(L"NotchMode") != 0;
    c.dockScreenEdge = Wh_GetIntSetting(L"DockToScreenEdge") != 0;
    {
        std::wstring sz = GetStringSetting(L"Size");
        c.uiSize = (sz == L"big") ? 1.0 : (sz == L"medium") ? 0.88 : 0.76;  // default: small
    }
    c.confirmPower = Wh_GetIntSetting(L"ConfirmPowerCommands") != 0;
    c.placeholder = GetStringSetting(L"Placeholder");
    {
        std::wstring wp = GetStringSetting(L"WindowPrefix");
        c.winPrefix = (wp == L"hash") ? L'#' : (wp == L"lt") ? L'<' : (wp == L"off") ? L'\0' : L'@';
    }

    g_cfg = c;
}

// ===== Interface sounds =====
// Every sound is generated in code, so they need no audio files and no internet. Playback goes
// through XAudio2 when it is available (it lets the short typing sounds overlap naturally); if it
// is not present, the sounds are simply skipped. The sounds are deliberately quiet and short:
// rounded switch-like clicks with a low-pass, no reverb and no bright tones. Typing is a deep,
// creamy "thock" in the style of a lubed linear switch (Cherry MX Black), with a small difference
// from key to key.
namespace Sound {

static const int kRate = 44100;
static const int kVoices = 12;  // enough to overlap fast typing

typedef HRESULT(WINAPI* XAudio2Create_t)(IXAudio2**, UINT32, XAUDIO2_PROCESSOR);

struct Engine {
    HMODULE dll = nullptr;
    IXAudio2* engine = nullptr;
    IXAudio2MasteringVoice* master = nullptr;
    IXAudio2SourceVoice* voices[kVoices] = {};
    int cursor = 0;
    bool ready = false;
    float volume = 0.7f;
    WAVEFORMATEX fmt = {};
    std::vector<std::vector<int16_t>> samples;
};

static Engine g_eng;
static unsigned g_rng = 0x9E3779B9u;

// XAudio2 reports a lost output device (unplugged headset, disabled device...) through
// OnCriticalError, on its own audio thread. StartEngine can still succeed afterwards with no
// audible output, so the flag is what tells Resume() to rebuild the engine.
struct EngineCallback : IXAudio2EngineCallback {
    std::atomic<bool> lost{false};
    void STDMETHODCALLTYPE OnProcessingPassStart() override {}
    void STDMETHODCALLTYPE OnProcessingPassEnd() override {}
    void STDMETHODCALLTYPE OnCriticalError(HRESULT) override { lost = true; }
};
static EngineCallback g_engineCallback;

static double Rand01() {
    g_rng = g_rng * 1664525u + 1013904223u;
    return (double)((g_rng >> 8) & 0xFFFFFF) / 16777216.0;
}

// ---- Sound design -------------------------------------------------------------------------
// The goal is "quiet and soft", like the click of a flashlight button: very short, rounded sounds
// with no reverb, no bright partials and a low-pass on top so nothing ever feels sharp.
//   AddTone  - a soft rounded body (a short sine whose pitch settles a little, like a plastic key
//              being pressed) with an optional faint second partial.
//   AddNoise - a tiny band-passed contact "tk", mixed in very low.
// Finish() rounds the top with a low-pass, sets a deliberately low peak level and fades the tail.
static const double kPi = 3.14159265358979323846;

static std::vector<float> NewBuf(double sec) {
    return std::vector<float>((size_t)(sec * kRate), 0.0f);
}

static void AddTone(std::vector<float>& buf, double startSec, double f0, double f1, double glideSec,
                    double attackSec, double tau, double gain, double bright, double detuneCents) {
    const int start = (int)(startSec * kRate);
    if (start >= (int)buf.size()) return;
    const double dt = 1.0 / kRate;
    const double ratio[3] = {1.0, 2.0, 3.0};
    const double amp[3] = {1.0, 0.42 * bright, 0.16 * bright};
    const double up = std::pow(2.0, detuneCents / 1200.0), down = 1.0 / up;
    double ph[3][2] = {};
    int n = (int)((attackSec + tau * 7.0) * kRate);
    for (int i = 0; i < n; ++i) {
        const int idx = start + i;
        if (idx >= (int)buf.size()) break;
        const double t = i * dt;
        const double g = glideSec > 0.0 ? 1.0 - std::exp(-t / glideSec) : 1.0;
        const double f = f0 + (f1 - f0) * g;
        double att = 1.0;
        double dec = 0.0;
        if (t < attackSec) {
            const double a = t / attackSec;
            att = a * a * (3.0 - 2.0 * a);
        } else {
            dec = t - attackSec;
        }
        double s = 0.0;
        for (int k = 0; k < 3; ++k) {
            if (amp[k] <= 0.0) continue;
            const double fk = f * ratio[k];
            ph[k][0] += 2.0 * kPi * fk * up * dt;
            ph[k][1] += 2.0 * kPi * fk * down * dt;
            const double env = att * std::exp(-dec * (1.0 + 0.9 * k) / tau);  // upper partials die first
            s += amp[k] * env * 0.5 * (std::sin(ph[k][0]) + std::sin(ph[k][1]));
        }
        buf[idx] += (float)(s * gain);
    }
}

static void AddNoise(std::vector<float>& buf, double startSec, double durSec, double fc0, double fc1,
                     double Q, double attackSec, double tau, double gain) {
    const int start = (int)(startSec * kRate);
    const int n = (int)(durSec * kRate);
    double low = 0.0, band = 0.0;
    const double q = 1.0 / Q;
    for (int i = 0; i < n; ++i) {
        const int idx = start + i;
        if (idx < 0 || idx >= (int)buf.size()) break;
        const double t = (double)i / kRate;
        const double x = (double)i / n;
        const double fc = fc0 * std::pow(fc1 / fc0, x);
        const double f = 2.0 * std::sin(kPi * fc / kRate);
        g_rng = g_rng * 1664525u + 1013904223u;
        const double in = (double)((g_rng >> 9) & 0x7FFF) / 16384.0 - 1.0;
        low += f * band;
        const double high = in - low - q * band;
        band += f * high;
        double env;
        if (t < attackSec) {
            const double a = t / attackSec;
            env = a * a * (3.0 - 2.0 * a);
        } else {
            env = std::exp(-(t - attackSec) / tau);
        }
        buf[idx] += (float)(band * env * gain);
    }
}

static void Finish(std::vector<float>& x, std::vector<int16_t>& out, double lpHz, double peak,
                   double fadeSec) {
    const double dt = 1.0 / kRate;
    const double alpha = dt / (1.0 / (2.0 * kPi * lpHz) + dt);
    double lp = 0.0, mx = 1e-9;
    for (size_t i = 0; i < x.size(); ++i) {
        lp += alpha * (x[i] - lp);
        x[i] = (float)lp;
        mx = std::max(mx, (double)std::fabs(x[i]));
    }
    const double scale = peak / mx;
    int fade = std::min((int)(fadeSec * kRate), (int)x.size());
    out.assign(x.size(), 0);
    for (size_t i = 0; i < x.size(); ++i) {
        double v = x[i] * scale;
        const int fromEnd = (int)x.size() - 1 - (int)i;
        if (fromEnd < fade) {
            const double a = (double)fromEnd / fade;
            v *= a * a * (3.0 - 2.0 * a);
        }
        out[i] = (int16_t)std::lround(std::clamp(v, -1.0, 1.0) * 32000.0);
    }
}

// Typing has one sample per key: a-z (0-25), 0-9 (26-35), space (36) and four punctuation groups.
enum { S_OPEN = 0, S_PANEL_ON = 1, S_PANEL_OFF = 2, S_TYPE = 3, S_TYPE_N = 41,
       S_ERASE = S_TYPE + S_TYPE_N, S_ERASE_N = 2, S_COUNT = S_ERASE + S_ERASE_N };

// Opening the bar: a soft two-stage switch click, press then a lighter release (flashlight button).
static void RenderOpen(std::vector<int16_t>& out) {
    std::vector<float> b = NewBuf(0.15);
    AddTone(b, 0.000, 520.0, 330.0, 0.010, 0.0008, 0.014, 1.00, 0.12, 0.0);   // press: round body
    AddNoise(b, 0.000, 0.012, 2400.0, 2400.0, 1.0, 0.0003, 0.0025, 0.30);     // soft contact
    AddTone(b, 0.048, 760.0, 560.0, 0.008, 0.0006, 0.008, 0.32, 0.05, 0.0);   // release: lighter
    AddNoise(b, 0.048, 0.008, 2800.0, 2800.0, 1.0, 0.0002, 0.0018, 0.12);
    Finish(b, out, 3000.0, 0.24, 0.040);
}

// Details panel: one tiny tick, a little higher when it opens and a little lower when it closes.
static void RenderPanel(std::vector<int16_t>& out, bool opening) {
    std::vector<float> b = NewBuf(0.10);
    if (opening) AddTone(b, 0.0, 420.0, 560.0, 0.014, 0.0008, 0.016, 1.00, 0.08, 0.0);
    else         AddTone(b, 0.0, 520.0, 380.0, 0.014, 0.0008, 0.016, 1.00, 0.08, 0.0);
    AddNoise(b, 0.0, 0.010, 2200.0, 2200.0, 1.0, 0.0003, 0.0020, 0.14);
    Finish(b, out, 2800.0, opening ? 0.17 : 0.15, 0.030);
}

// Evenly spread, repeatable "random" numbers: every key always gets the same character.
static double Hash01(int slot, int salt) {
    const double k[8] = {0.6180339887, 0.7548776662, 0.5698402910, 0.8191725134,
                         0.4142135624, 0.7320508076, 0.3247179572, 0.2360679775};
    const double v = (slot + 1) * k[salt & 7] + 0.137 * salt;
    return v - std::floor(v);
}

// Deep, creamy bottom-out: the soft "thock" of a well-lubed linear switch (Cherry MX Black style).
// A low body that settles down on impact, a couple of quiet inharmonic case resonances for the
// boxy colour, and a short, low-passed contact "clack" on top. Nothing bright: it is rounded on
// purpose so it stays creamy instead of clicky.
//   base     - resting pitch in Hz (lower = deeper)
//   tauScale - scales how long it rings
static void RenderTick(std::vector<int16_t>& out, double base, double tauScale, double peak) {
    std::vector<float> b = NewBuf(0.10);
    AddTone(b, 0.0, base * 1.20, base, 0.007, 0.0007, 0.021 * tauScale, 1.00, 0.12, 9.0);
    AddTone(b, 0.0, base * 2.32, base * 2.12, 0.006, 0.0007, 0.011 * tauScale, 0.24, 0.0, 6.0);
    AddTone(b, 0.0, base * 3.45, base * 3.18, 0.005, 0.0007, 0.007 * tauScale, 0.09, 0.0, 0.0);
    AddNoise(b, 0.0, 0.011, 1600.0, 900.0, 0.9, 0.0003, 0.0020, 0.16);
    Finish(b, out, 2400.0, peak, 0.020);
}

// Every key is the same deep thock with a slightly different pitch and ring, so typing has a
// natural, creamy variety. The space bar is a touch lower and rounder.
static void RenderType(std::vector<int16_t>& out, int slot) {
    if (slot == 36) {  // space bar: lower and rounder
        std::vector<float> b = NewBuf(0.13);
        AddTone(b, 0.0, 155.0 * 1.20, 155.0, 0.008, 0.0008, 0.030, 1.00, 0.12, 9.0);
        AddTone(b, 0.0, 155.0 * 2.32, 155.0 * 2.12, 0.007, 0.0008, 0.016, 0.22, 0.0, 6.0);
        AddNoise(b, 0.0, 0.012, 1400.0, 800.0, 0.9, 0.0003, 0.0022, 0.16);
        Finish(b, out, 2200.0, 0.090, 0.025);
        return;
    }
    const double base = 190.0 * (0.90 + 0.20 * ((slot * 17) % 41) / 40.0);  // +-10% pitch, all different
    const double tauScale = 0.90 + 0.20 * Hash01(slot, 3);
    RenderTick(out, base, tauScale, 0.070 + 0.012 * Hash01(slot, 7));
}

// Which "key" a typed character uses.
static int KeySlot(wchar_t c) {
    if (c >= L'A' && c <= L'Z') c = (wchar_t)(c - L'A' + L'a');
    if (c >= L'a' && c <= L'z') return (int)(c - L'a');
    if (c >= L'0' && c <= L'9') return 26 + (int)(c - L'0');
    if (c == L' ') return 36;
    if (c > 127) return (int)(c % 26);  // accents, ñ, etc. share the letter keys
    return 37 + (int)(c % 4);
}

// Backspace: the same thock, a bit lower and softer.
static void RenderErase(std::vector<int16_t>& out, int v) {
    RenderTick(out, 150.0 + 10.0 * v, 1.15, 0.065);
}

static void RenderAll() {
    g_eng.samples.assign(S_COUNT, {});
    RenderOpen(g_eng.samples[S_OPEN]);
    RenderPanel(g_eng.samples[S_PANEL_ON], true);
    RenderPanel(g_eng.samples[S_PANEL_OFF], false);
    for (int i = 0; i < S_TYPE_N; ++i) RenderType(g_eng.samples[S_TYPE + i], i);
    for (int i = 0; i < S_ERASE_N; ++i) RenderErase(g_eng.samples[S_ERASE + i], i);
}

static bool Init() {
    if (g_eng.samples.empty()) RenderAll();
    Engine& e = g_eng;
    e.dll = LoadLibraryExW(L"xaudio2_9.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!e.dll) e.dll = LoadLibraryExW(L"xaudio2_8.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!e.dll) return false;
    XAudio2Create_t create = (XAudio2Create_t)GetProcAddress(e.dll, "XAudio2Create");
    if (!create) return false;
    if (FAILED(create(&e.engine, 0, XAUDIO2_DEFAULT_PROCESSOR)) || !e.engine) return false;
    g_engineCallback.lost = false;
    e.engine->RegisterForCallbacks(&g_engineCallback);
    if (FAILED(e.engine->CreateMasteringVoice(&e.master)) || !e.master) return false;
    e.fmt.wFormatTag = WAVE_FORMAT_PCM;
    e.fmt.nChannels = 1;
    e.fmt.nSamplesPerSec = kRate;
    e.fmt.wBitsPerSample = 16;
    e.fmt.nBlockAlign = 2;
    e.fmt.nAvgBytesPerSec = kRate * 2;
    e.fmt.cbSize = 0;
    for (int i = 0; i < kVoices; ++i) {
        if (FAILED(e.engine->CreateSourceVoice(&e.voices[i], &e.fmt))) e.voices[i] = nullptr;
    }
    // XAudio2 starts its engine on creation: keep it stopped (no audio thread / render stream)
    // until the bar opens with sounds enabled.
    e.engine->StopEngine();
    e.ready = true;
    return true;
}

static void Shutdown() {
    Engine& e = g_eng;
    if (e.engine) {
        for (int i = 0; i < kVoices; ++i) {
            if (e.voices[i]) { e.voices[i]->DestroyVoice(); e.voices[i] = nullptr; }
        }
        if (e.master) { e.master->DestroyVoice(); e.master = nullptr; }
        e.engine->UnregisterForCallbacks(&g_engineCallback);
        e.engine->Release();
        e.engine = nullptr;
    }
    if (e.dll) { FreeLibrary(e.dll); e.dll = nullptr; }
    e.ready = false;
}

// The engine only runs while the bar is open and sounds are enabled.
// If there was no output device at startup, or the device was removed (the engine then reports
// a critical error, see EngineCallback), rebuild the engine here before starting it.
static void Resume() {
    if (!g_cfg.sounds) return;
    Engine& e = g_eng;
    if (e.ready && e.engine && !g_engineCallback.lost && SUCCEEDED(e.engine->StartEngine())) return;
    Shutdown();
    if (Init() && e.engine) e.engine->StartEngine();
}
static void Suspend() { if (g_eng.engine) g_eng.engine->StopEngine(); }

// Creates the engine only when sounds are on; releases it completely when they are off.
static void Configure() {
    if (g_cfg.sounds) {
        if (!g_eng.ready) {
            Shutdown();  // clean up any partial init before retrying
            Init();
        }
    } else {
        Shutdown();
    }
}

static void ApplyVolume() {
    g_eng.volume = (float)std::clamp(g_cfg.soundVolume, 0, 100) / 100.0f;
}

static void Play(int idx, double pitch, double gain) {
    Engine& e = g_eng;
    if (!e.ready || idx < 0 || idx >= (int)e.samples.size()) return;
    std::vector<int16_t>& pcm = e.samples[idx];
    if (pcm.empty()) return;
    IXAudio2SourceVoice* v = e.voices[e.cursor];
    e.cursor = (e.cursor + 1) % kVoices;
    if (!v) return;
    v->Stop(0);
    v->FlushSourceBuffers();
    v->SetFrequencyRatio((float)pitch);
    v->SetVolume((float)(gain * e.volume));
    XAUDIO2_BUFFER buf = {};
    buf.AudioBytes = (UINT32)(pcm.size() * sizeof(int16_t));
    buf.pAudioData = (const BYTE*)pcm.data();
    buf.Flags = XAUDIO2_END_OF_STREAM;
    if (FAILED(v->SubmitSourceBuffer(&buf))) return;
    v->Start(0);
}

static bool On() { return g_cfg.sounds; }

static int PickVariant(int n, int& last) {
    int v = (int)(Rand01() * n) % n;
    if (v == last) v = (v + 1) % n;  // never the same variant twice in a row
    last = v;
    return v;
}

static int g_lastErase = -1;

static void OnOpen() { if (On()) Play(S_OPEN, 1.0, 1.0); }
static void OnPanel(bool opening) { if (On()) Play(opening ? S_PANEL_ON : S_PANEL_OFF, 1.0, 1.0); }
// c is the typed character; each key always sounds like itself (with a tiny human wobble).
// With no character (paste) a random letter key is used.
static void OnKey(wchar_t c = 0) {
    if (!On()) return;
    const int slot = c ? KeySlot(c) : (int)(Rand01() * 26.0) % 26;
    Play(S_TYPE + slot, 0.985 + Rand01() * 0.03, 0.88 + Rand01() * 0.12);
}
static void OnErase() {
    if (On()) Play(S_ERASE + PickVariant(S_ERASE_N, g_lastErase), 0.95 + Rand01() * 0.07, 0.85 + Rand01() * 0.15);
}

}  // namespace Sound

static D2D1_COLOR_F Mix(const D2D1_COLOR_F& a, const D2D1_COLOR_F& b, float t, float alpha = 1.f) {
    return D2D1::ColorF(a.r + (b.r - a.r) * t, a.g + (b.g - a.g) * t, a.b + (b.b - a.b) * t, alpha);
}

// "#RRGGBB", "RRGGBB" or "#RGB" -> 0..1 floats.
static bool ParseHexColor(const std::wstring& in, float out[3]) {
    std::wstring t = in;
    while (!t.empty() && iswspace(t.front())) t.erase(t.begin());
    while (!t.empty() && iswspace(t.back())) t.pop_back();
    if (!t.empty() && t[0] == L'#') t.erase(t.begin());
    if (t.size() == 3) {
        std::wstring d;
        for (wchar_t c : t) {
            d += c;
            d += c;
        }
        t = d;
    }
    if (t.size() != 6) return false;
    unsigned v = 0;
    for (wchar_t c : t) {
        int d = Calc::detail::DigitVal(c);
        if (d < 0) return false;
        v = v * 16 + (unsigned)d;
    }
    out[0] = ((v >> 16) & 255) / 255.f;
    out[1] = ((v >> 8) & 255) / 255.f;
    out[2] = (v & 255) / 255.f;
    return true;
}

// Builds the whole palette from the chosen color (background + accents).
static void LoadPalette() {
    SafeRelease(g_gradBrush);  // the gradients depend on the current palette
    SafeRelease(g_glow1);
    SafeRelease(g_glow2);
    const int nColors = (int)(sizeof(kColors) / sizeof(kColors[0]));
    ColorDef cd = kColors[std::clamp(g_cfg.colorIdx, 0, nColors - 1)];
    {
        float rgb[3];
        if (ParseHexColor(g_cfg.customBg, rgb)) {
            for (int k = 0; k < 3; ++k) cd.bg[k] = rgb[k];
            const float lum = 0.2126f * rgb[0] + 0.7152f * rgb[1] + 0.0722f * rgb[2];
            cd.light = lum > 0.62f;
        }
        if (ParseHexColor(g_cfg.customAccent, rgb)) {
            for (int k = 0; k < 3; ++k) {
                cd.acc[k] = rgb[k];
                cd.acc2[k] = rgb[k] + (1.f - rgb[k]) * 0.35f;
            }
        }
    }
    const float op = g_cfg.opacityPct / 100.f;
    const D2D1_COLOR_F white = D2D1::ColorF(1.f, 1.f, 1.f, 1.f);
    const D2D1_COLOR_F A = D2D1::ColorF(cd.acc[0], cd.acc[1], cd.acc[2], 1.f);
    const D2D1_COLOR_F A2 = D2D1::ColorF(cd.acc2[0], cd.acc2[1], cd.acc2[2], 1.f);

    g_pal.light = cd.light;
    g_pal.accent = A;
    g_pal.accent2 = A2;
    g_pal.bg = D2D1::ColorF(cd.bg[0], cd.bg[1], cd.bg[2], op);

    if (cd.light) {
        // Light: dark ink with a hint of the accent; borders and keys are subtle.
        const D2D1_COLOR_F ink = Mix(D2D1::ColorF(0.09f, 0.11f, 0.16f), A, 0.10f);
        g_pal.border = D2D1::ColorF(ink.r, ink.g, ink.b, 0.18f);
        g_pal.text = ink;
        g_pal.textDim = Mix(ink, white, 0.45f);
        g_pal.selection = D2D1::ColorF(A.r, A.g, A.b, 0.13f);
        g_pal.separator = D2D1::ColorF(ink.r, ink.g, ink.b, 0.10f);
        g_pal.keycap = D2D1::ColorF(ink.r, ink.g, ink.b, 0.08f);
        g_pal.match = Mix(A, D2D1::ColorF(0.f, 0.f, 0.f), 0.10f);
        g_pal.caretSel = D2D1::ColorF(A.r, A.g, A.b, 0.25f);
        g_pal.shadowAlpha = 0.025f;
    } else {
        // Dark: near-white letters tinted with the accent, translucent layers of the same hue.
        g_pal.border = Mix(white, A, 0.30f, 0.19f);
        g_pal.text = Mix(white, A, 0.07f);
        g_pal.textDim = Mix(D2D1::ColorF(0.64f, 0.65f, 0.68f), A, 0.22f);
        g_pal.selection = D2D1::ColorF(A.r * 0.8f, A.g * 0.8f, A.b * 0.8f, 0.30f);
        g_pal.separator = Mix(white, A, 0.30f, 0.11f);
        g_pal.keycap = Mix(white, A, 0.30f, 0.13f);
        g_pal.match = Mix(A, white, 0.20f);
        g_pal.caretSel = D2D1::ColorF(A.r, A.g, A.b, 0.40f);
        g_pal.shadowAlpha = 0.040f;
    }

    if (g_matchBrush) {
        g_matchBrush->SetColor(&g_pal.match);
    }
}
// ===== Search =====

static bool IsWordStart(const std::wstring& name, size_t p) {
    if (p == 0) {
        return iswalnum(name[0]) != 0;
    }
    wchar_t prev = name[p - 1];
    wchar_t cur = name[p];
    if (!iswalnum(prev)) {
        return iswalnum(cur) != 0;
    }
    return iswlower(prev) && iswupper(cur);  // camelCase: WhatsApp -> W, A
}

// Scores a token against a name. 0 = no match. If mask != nullptr it marks the
// matching positions (to highlight them).
static int ScoreToken(const std::wstring& name,
                      const std::wstring& f,
                      const std::wstring& tok,
                      std::vector<char>* mask) {
    const size_t n = f.size();
    const size_t m = tok.size();
    if (m == 0 || n == 0) {
        return 0;
    }

    auto markRange = [&](size_t a, size_t len) {
        if (!mask) return;
        for (size_t i = a; i < a + len && i < n; ++i) (*mask)[i] = 1;
    };

    if (m <= n) {
        if (f == tok) {
            markRange(0, m);
            return 1000;
        }
        if (f.compare(0, m, tok) == 0) {
            markRange(0, m);
            return 900 - (int)std::min<size_t>(n - m, 150);
        }
        for (size_t p = 1; p + m <= n; ++p) {
            if (IsWordStart(name, p) && f.compare(p, m, tok) == 0) {
                markRange(p, m);
                return 700 - (int)std::min<size_t>(p, 100);
            }
        }
        size_t pos = f.find(tok);
        if (pos != std::wstring::npos) {
            markRange(pos, m);
            return 500 - (int)std::min<size_t>(pos, 100);
        }
    }

    // Acronyms: the initials of each word in the name
    {
        std::vector<size_t> ini;
        for (size_t p = 0; p < n; ++p) {
            if (IsWordStart(name, p)) ini.push_back(p);
        }
        if (m >= 2 && m <= ini.size()) {
            size_t k = 0;
            std::vector<size_t> hit;
            for (size_t i = 0; i < ini.size() && k < m; ++i) {
                if (f[ini[i]] == tok[k]) {
                    hit.push_back(ini[i]);
                    ++k;
                }
            }
            if (k == m) {
                if (mask) {
                    for (size_t p : hit) (*mask)[p] = 1;
                }
                return 420 - (int)std::min<size_t>(ini.size() - m, 50);
            }
        }
    }

    // Fuzzy subsequence
    if (m >= 2 && m <= n) {
        std::vector<size_t> hit;
        size_t from = 0;
        for (size_t k = 0; k < m; ++k) {
            size_t q = f.find(tok[k], from);
            if (q == std::wstring::npos) {
                return 0;
            }
            // Prefer a nearby word start
            for (size_t r = q; r < n && r <= q + 6; ++r) {
                if (f[r] == tok[k] && IsWordStart(name, r)) {
                    q = r;
                    break;
                }
            }
            hit.push_back(q);
            from = q + 1;
        }
        size_t span = hit.back() - hit.front() + 1;
        if (span > m * 3 + 6) {
            return 0;
        }
        int score = 100;
        for (size_t i = 0; i < hit.size(); ++i) {
            if (IsWordStart(name, hit[i])) score += 8;
            if (i > 0) {
                size_t gap = hit[i] - hit[i - 1] - 1;
                if (gap == 0) {
                    score += 18;
                } else {
                    score -= (int)std::min<size_t>(gap * 2, 20);
                }
            }
        }
        if (mask) {
            for (size_t p : hit) (*mask)[p] = 1;
        }
        return std::clamp(score, 20, 380);
    }

    return 0;
}

static std::vector<std::wstring> Tokenize(const std::wstring& text) {
    std::vector<std::wstring> out;
    std::wstring cur;
    for (wchar_t c : text) {
        if (c == L' ' || c == L'\t') {
            if (!cur.empty()) {
                out.push_back(FoldString(cur));
                cur.clear();
            }
        } else {
            cur.push_back(c);
        }
    }
    if (!cur.empty()) {
        out.push_back(FoldString(cur));
    }
    return out;
}

static void ReleaseResultLayouts() {
    for (auto& r : g_results) {
        SafeRelease(r.layout);
    }
}

// Vertical position (DIP, from the top of the list) of each row, counting section
// headers. Without sections it is simply i * kRowH.
static void BuildRowOffsets() {
    g_rowOff.clear();
    g_headerCount = 0;
    int prev = 0;
    float y = 0;
    for (size_t i = 0; i < g_results.size(); ++i) {
        int sec = g_results[i].section;
        if (sec != 0 && sec != prev) {
            y += kSectionH;
            ++g_headerCount;
        }
        prev = sec;
        g_rowOff.push_back(y);
        y += kRowH;
    }
    g_rowOff.push_back(y);
}

// Same as g_rowOff, but for a fractional position (highlight and scroll animations).
static double RowOffset(double pos) {
    const int n = (int)g_results.size();
    if (n == 0 || g_rowOff.size() != (size_t)n + 1) return pos * kRowH;
    if (pos <= 0) return g_rowOff[0] + pos * kRowH;
    int i = (int)std::floor(pos);
    if (i >= n) return g_rowOff[n] + (pos - n) * kRowH;
    double f = pos - i;
    double a = g_rowOff[i];
    double b = (i + 1 < n) ? g_rowOff[i + 1] : g_rowOff[i] + kRowH;
    return a + (b - a) * f;
}

// Scroll offset in DIP, measured from the first row (with scroll 0 it is 0, so the
// header of the first section keeps its slot).
static double ScrollPx() {
    return RowOffset(g_scrollPos) - RowOffset(0.0);
}

// Common Windows apps to fill "Suggestions" when there is still no usage history. They are
// looked up by fragments of the identifier (they do not change with the Windows language);
// the ones that do not exist on the machine are simply skipped.
static const wchar_t* const kDefaultSuggestions[] = {
    L"microsoft.windows.explorer", L"windowsterminal", L"windowscalculator", L"windowsnotepad",
    L"immersivecontrolpanel",     L"msedge",           L"taskmgr",           L"taskmanager",
    L"screensketch",              L"microsoft.paint",  L"windows.photos",    L"windowsstore",
    L"windowsalarms",             L"cmd.exe",          L"powershell",
};

static std::wstring LowerAscii(std::wstring s) {
    for (auto& c : s) {
        if (c >= L'A' && c <= L'Z') c = (wchar_t)(c + 32);
    }
    return s;
}

// Expanded mode with an empty search bar: "Recent" (last opened apps) and "Suggestions"
// (the most used ones and, so the list is never empty, common system apps).
// All entries are returned; the list scrolls inside the fixed panel height.
static void BuildHome() {
    std::vector<SearchResult> rec;
    for (size_t i = 0; i < g_apps.size(); ++i) {
        if (g_apps[i].lastUsed > 0) {
            SearchResult r;
            r.app = (int)i;
            r.score = g_apps[i].lastUsed;
            rec.push_back(r);
        }
    }
    std::sort(rec.begin(), rec.end(), [](const SearchResult& a, const SearchResult& b) {
        if (a.score != b.score) return a.score > b.score;
        return g_apps[a.app].folded < g_apps[b.app].folded;
    });
    if (rec.size() > kMaxRecents) rec.resize(kMaxRecents);

    std::unordered_set<int> taken;
    for (const auto& r : rec) taken.insert(r.app);

    // Suggestions: first the most used, then the common system apps
    std::vector<int> pool;
    {
        std::vector<SearchResult> byUse;
        for (size_t i = 0; i < g_apps.size(); ++i) {
            if (g_apps[i].uses > 0 && !taken.count((int)i)) {
                SearchResult r;
                r.app = (int)i;
                r.score = g_apps[i].uses;
                byUse.push_back(r);
            }
        }
        std::sort(byUse.begin(), byUse.end(), [](const SearchResult& a, const SearchResult& b) {
            if (a.score != b.score) return a.score > b.score;
            return g_apps[a.app].folded < g_apps[b.app].folded;
        });
        for (const auto& r : byUse) {
            pool.push_back(r.app);
            taken.insert(r.app);
        }

        std::vector<std::wstring> lowIds(g_apps.size());
        for (size_t i = 0; i < g_apps.size(); ++i) lowIds[i] = LowerAscii(g_apps[i].id);
        for (const wchar_t* frag : kDefaultSuggestions) {
            for (size_t i = 0; i < g_apps.size(); ++i) {
                if (!taken.count((int)i) && lowIds[i].find(frag) != std::wstring::npos) {
                    pool.push_back((int)i);
                    taken.insert((int)i);
                    break;
                }
            }
        }
    }

    const size_t nr = rec.size();
    const size_t ns = pool.size();

    for (size_t i = 0; i < nr; ++i) {
        rec[i].section = 1;
        g_results.push_back(rec[i]);
    }
    for (size_t i = 0; i < ns; ++i) {
        SearchResult r;
        r.app = pool[i];
        r.score = (int)(ns - i);
        r.section = 2;
        g_results.push_back(r);
    }
}

// ===== Calculator state =====

// True when there is a valid result to offer (copy, inline text).
static bool CalcOk() {
    return g_calcActive && g_calc.status == Calc::Status::Ok;
}

// The result card is shown for a result or an error, unless the user asked for inline only.
static bool HeroShown() {
    return g_calcActive && g_cfg.calcStyle != CalcStyle::Ghost;
}

// The faint inline text is only shown for a real result, unless the user asked for the card only.
static bool GhostShown() {
    return CalcOk() && g_cfg.calcStyle != CalcStyle::Hero;
}

// Height (DIP) reserved above the list for the result card.
static double HeroH() {
    return HeroShown() ? kHeroH : 0.0;
}

// True when the calculation is actually visible (card or inline text).
static bool CalcShown() {
    return HeroShown() || GhostShown();
}

static void UpdateCalc() {
    g_calc = Calc::Result();
    g_calcDisplay.clear();
    g_calcActive = false;
    if (!g_cfg.calculatorEnabled || g_text.empty()) {
        return;
    }
    Calc::Context ctx;
    ctx.hasAns = g_calcHasAns;
    ctx.ans = g_calcAns;
    Calc::Result r = Calc::Evaluate(g_text, Calc::SystemLocale(), ctx);
    if (r.status == Calc::Status::Ok) {
        g_calc = r;
        g_calcDisplay = r.display.empty() ? Calc::Format(r.value, Calc::SystemLocale()) : r.display;
        g_calcActive = true;
    } else if (r.status == Calc::Status::Error) {
        g_calc = r;
        g_calcActive = true;
    }
}

// What Enter copies: the bare number, so it pastes cleanly into other apps. The display text
// adds thousands separators, the unit and (for data sizes) the other reading in brackets. Base
// conversions are the exception: their digits only make sense as shown (e.g. "0xFF").
static std::wstring CalcClipboardText() {
    if (!g_calc.display.empty() && g_calc.insertable == g_calc.display) {
        return g_calc.display;
    }
    Calc::Locale plain = Calc::SystemLocale();
    plain.grouping = false;
    return Calc::Format(g_calc.value, plain);
}

// SID of the current user. Windhawk's Wh_Get/SetIntValue storage is machine-wide in a regular
// install, and each signed-in user runs their own tool process, so put the SID in the value
// names; otherwise "Recent" and "Suggestions" would be shared by every account on the PC.
static std::wstring CurrentUserSid() {
    static std::wstring sid;
    if (!sid.empty()) return sid;
    HANDLE token = nullptr;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token) && token) {
        DWORD size = 0;
        GetTokenInformation(token, TokenUser, nullptr, 0, &size);
        if (size > 0) {
            std::vector<BYTE> buf(size);
            TOKEN_USER* user = reinterpret_cast<TOKEN_USER*>(buf.data());
            if (GetTokenInformation(token, TokenUser, user, size, &size) && user->User.Sid) {
                LPWSTR str = nullptr;
                if (ConvertSidToStringSidW(user->User.Sid, &str) && str) {
                    sid = str;
                    LocalFree(str);
                }
            }
        }
        CloseHandle(token);
    }
    if (sid.empty()) sid = L"shared";  // fallback: degrade to machine-wide if the SID fails
    return sid;
}

// ===== Calculator history (persisted in the mod's local storage) =====

// Per-user names: Windhawk storage is machine-wide, so the SID keeps accounts separate.
static std::wstring CalcHistKey() { return L"calc.history_" + CurrentUserSid(); }
static const size_t kCalcHistMax = 10;

static void TrimHistField(std::wstring& s) {
    for (auto& c : s) {
        if (c == L'\n' || c == L'\r' || c == L'\t') c = L' ';
    }
}

static void LoadCalcHistory() {
    g_calcHist.clear();
    wchar_t buf[8192] = {};
    size_t n = Wh_GetStringValue(CalcHistKey().c_str(), buf, ARRAYSIZE(buf));
    if (n == 0) return;
    std::wstring all(buf, n);
    size_t start = 0;
    while (start <= all.size() && g_calcHist.size() < kCalcHistMax) {
        size_t nl = all.find(L'\n', start);
        std::wstring line =
            all.substr(start, nl == std::wstring::npos ? std::wstring::npos : nl - start);
        start = (nl == std::wstring::npos) ? all.size() + 1 : nl + 1;
        if (line.empty()) continue;
        size_t tab1 = line.find(L'\t');
        CalcHistoryItem it;
        if (tab1 == std::wstring::npos) {
            it.expr = line;
        } else {
            it.expr = line.substr(0, tab1);
            size_t tab2 = line.find(L'\t', tab1 + 1);
            if (tab2 == std::wstring::npos) {
                it.resFmt = line.substr(tab1 + 1);
            } else {
                it.resFmt = line.substr(tab1 + 1, tab2 - tab1 - 1);
                it.insVal = line.substr(tab2 + 1);
            }
        }
        if (it.insVal.empty()) it.insVal = it.resFmt;
        if (!it.expr.empty()) g_calcHist.push_back(it);
    }
}

static void SaveCalcHistory() {
    std::wstring all;
    for (size_t i = 0; i < g_calcHist.size(); ++i) {
        if (i) all += L'\n';
        all += g_calcHist[i].expr;
        all += L'\t';
        all += g_calcHist[i].resFmt;
        all += L'\t';
        all += g_calcHist[i].insVal.empty() ? g_calcHist[i].resFmt : g_calcHist[i].insVal;
    }
    Wh_SetStringValue(CalcHistKey().c_str(), all.c_str());
}

// "ans": the last committed result, persisted so it survives a restart.
static std::wstring CalcAnsKey() { return L"calc.ans_" + CurrentUserSid(); }

static void LoadCalcAns() {
    g_calcHasAns = false;
    wchar_t buf[64] = {};
    size_t n = Wh_GetStringValue(CalcAnsKey().c_str(), buf, ARRAYSIZE(buf));
    if (n == 0) return;
    double v = 0.0;
    if (Calc::detail::ParseCleanDecimal(buf, v)) {
        g_calcAns = v;
        g_calcHasAns = true;
    }
}

static void SetCalcAns(double v) {
    g_calcAns = v;
    g_calcHasAns = true;
    wchar_t buf[64] = {};
    swprintf(buf, ARRAYSIZE(buf), L"%.17g", v);
    Wh_SetStringValue(CalcAnsKey().c_str(), buf);
}

// Records a calculation the user committed (pressed Enter on). Repeating an expression moves it
// back to the top instead of duplicating it. When the list is full the oldest entry is dropped.
static void AddCalcHistory(const std::wstring& expr, const std::wstring& resFmt,
                           const std::wstring& insVal) {
    CalcHistoryItem it;
    it.expr = expr;
    it.resFmt = resFmt;
    it.insVal = insVal.empty() ? resFmt : insVal;
    TrimHistField(it.expr);
    TrimHistField(it.resFmt);
    TrimHistField(it.insVal);
    if (it.expr.empty()) return;
    for (size_t i = 0; i < g_calcHist.size();) {
        if (g_calcHist[i].expr == it.expr) {
            g_calcHist.erase(g_calcHist.begin() + i);
        } else {
            ++i;
        }
    }
    g_calcHist.insert(g_calcHist.begin(), it);
    if (g_calcHist.size() > kCalcHistMax) {
        g_calcHist.resize(kCalcHistMax);
    }
    SaveCalcHistory();
}

// ===== Power commands (">" prefix) =====
enum CmdId {
    CMD_SHUTDOWN = 0, CMD_RESTART, CMD_SLEEP, CMD_LOGOUT, CMD_LOCK,
    CMD_HIBERNATE, CMD_MUTE, CMD_VOLUP, CMD_VOLDOWN, CMD_PLAYPAUSE, CMD_NEXT, CMD_PREV,
    CMD_DARKMODE, CMD_DISPLAYOFF, CMD_SHOWDESKTOP, CMD_RECYCLE
};

struct CmdDef {
    int id;
    const wchar_t* name;
    const wchar_t* alias;
};

static const CmdDef kCmds[] = {
    {CMD_SHUTDOWN, L"Shutdown", L"shut down poweroff power off turn"},
    {CMD_RESTART, L"Restart", L"reboot"},
    {CMD_SLEEP, L"Sleep", L"suspend standby"},
    {CMD_LOGOUT, L"Logout", L"log out logoff log off sign out signout"},
    {CMD_LOCK, L"Lock", L"lock screen"},
    {CMD_HIBERNATE, L"Hibernate", L"hibernation"},
    {CMD_MUTE, L"Mute / Unmute", L"mute unmute sound audio volume silence"},
    {CMD_VOLUP, L"Volume up", L"louder sound audio"},
    {CMD_VOLDOWN, L"Volume down", L"quieter lower sound audio"},
    {CMD_PLAYPAUSE, L"Play / Pause", L"media music playpause"},
    {CMD_NEXT, L"Next track", L"media music skip"},
    {CMD_PREV, L"Previous track", L"media music back"},
    {CMD_DARKMODE, L"Toggle dark mode", L"theme light dark appearance"},
    {CMD_DISPLAYOFF, L"Turn off display", L"screen monitor off"},
    {CMD_SHOWDESKTOP, L"Show desktop", L"minimize all windows"},
    {CMD_RECYCLE, L"Empty Recycle Bin", L"trash bin delete"},
};

static int g_cmdArmed = -1;       // app index of the command waiting for a second Enter
static bool g_winListFresh = false;  // the window entries in g_apps were enumerated for this opening
static void BuildWindowResults();
static double g_cmdArmedAt = 0;

// The commands live in g_apps (flagged isCmd) so rows, selection and hit testing work unchanged;
// normal searches and the home list skip them.
static void AppendCommandEntries(std::vector<AppEntry>& v) {
    g_winListFresh = false;  // window entries are dropped together with the old app list
    for (const CmdDef& c : kCmds) {
        AppEntry a;
        a.name = c.name;
        a.folded = FoldString(a.name);
        a.id = L"@cmd:" + std::to_wstring(c.id);
        a.isCmd = true;
        a.cmdId = c.id;
        a.alias = c.alias;
        v.push_back(std::move(a));
    }
}

static void BuildCommandResults() {
    std::vector<SearchResult> out;
    for (size_t i = 0; i < g_apps.size(); ++i) {
        const AppEntry& a = g_apps[i];
        if (!a.isCmd) continue;
        int best = 1000 - a.cmdId;  // nothing typed: keep the declared order
        if (!g_tokens.empty()) {
            int total = 0;
            bool ok = true;
            for (const auto& tok : g_tokens) {
                int sc = ScoreToken(a.name, a.folded, tok, nullptr);
                size_t p = 0;
                while (p < a.alias.size()) {
                    size_t e = a.alias.find(L' ', p);
                    if (e == std::wstring::npos) e = a.alias.size();
                    const std::wstring w = a.alias.substr(p, e - p);
                    if (!w.empty()) sc = std::max(sc, ScoreToken(w, w, tok, nullptr));
                    p = e + 1;
                }
                if (sc <= 0) {
                    ok = false;
                    break;
                }
                total += sc;
            }
            if (!ok) continue;
            best = total / (int)g_tokens.size();
        }
        SearchResult r;
        r.app = (int)i;
        r.score = best;
        out.push_back(r);
    }
    std::sort(out.begin(), out.end(), [](const SearchResult& x, const SearchResult& y) {
        if (x.score != y.score) return x.score > y.score;
        return g_apps[x.app].cmdId < g_apps[y.app].cmdId;
    });
    g_results = out;
}

static void RunSearch() {
    ReleaseResultLayouts();
    g_results.clear();
    g_tokens = Tokenize(g_text);

    // The window prefix ("@" by default) lists the open windows; whatever follows filters them.
    const bool winMode = g_cfg.winPrefix != 0 && !g_text.empty() && g_text[0] == g_cfg.winPrefix;
    if (!winMode) g_winListFresh = false;
    if (winMode) {
        g_tokens = Tokenize(g_text.substr(1));
        BuildWindowResults();
        if (g_flip) std::reverse(g_results.begin(), g_results.end());
        BuildRowOffsets();
        return;
    }

    // ">" switches to the power commands; whatever follows filters them.
    if (!g_text.empty() && g_text[0] == L'>') {
        g_tokens = Tokenize(g_text.substr(1));
        BuildCommandResults();
        if (g_flip) std::reverse(g_results.begin(), g_results.end());
        BuildRowOffsets();
        return;
    }

    if (g_tokens.empty()) {
        // No query: Compact = nothing; Expanded = recents + suggestions.
        if (g_cfg.listMode == ListMode::Expanded) {
            BuildHome();
        }
        if (g_flip) std::reverse(g_results.begin(), g_results.end());
        BuildRowOffsets();
        return;
    }

    // A valid calculation is the only result: it is what Enter copies, so we do not mix it with
    // app matches (a query like "2+2" should never launch an app that happened to match).
    // Exception: a lone constant ("pi", "tau", "phi", "ans") only wins when no app matches,
    // so typing the start of "Pinta" or "PicPick" keeps showing the apps.
    const bool loneConst = CalcOk() && g_calc.loneConstant;
    if (CalcOk() && !loneConst) {
        BuildRowOffsets();
        return;
    }

    for (size_t i = 0; i < g_apps.size(); ++i) {
        const AppEntry& a = g_apps[i];
        if (a.isCmd) continue;
        int total = 0;
        bool ok = true;
        for (const auto& t : g_tokens) {
            int s = ScoreToken(a.name, a.folded, t, nullptr);
            if (s <= 0) {
                ok = false;
                break;
            }
            total += s;
        }
        if (!ok) {
            continue;
        }
        total /= (int)g_tokens.size();
        total += std::min(a.uses, 30) * 4;
        SearchResult r;
        r.app = (int)i;
        r.score = total;
        g_results.push_back(r);
    }

    std::sort(g_results.begin(), g_results.end(),
              [](const SearchResult& a, const SearchResult& b) {
                  if (a.score != b.score) return a.score > b.score;
                  return g_apps[a.app].folded < g_apps[b.app].folded;
              });
    // Cap the number of results. This only limits how many there are; the height of the
    // bar is fixed and rows that do not fit are reached by scrolling.
    if ((int)g_results.size() > g_cfg.maxRows) {
        g_results.resize((size_t)g_cfg.maxRows);
    }
    if (loneConst && !g_results.empty()) {
        g_calc = Calc::Result();  // apps matched: drop the constant's result card
        g_calcDisplay.clear();
        g_calcActive = false;
    }
    // Docked at the bottom: the best match goes next to the bar (last row).
    if (g_flip) std::reverse(g_results.begin(), g_results.end());
    BuildRowOffsets();
}

// ===== App indexing (background thread) =====

static bool EndsWith(const std::wstring& s, const wchar_t* suffix) {
    size_t n = wcslen(suffix);
    return s.size() >= n && s.compare(s.size() - n, n, suffix) == 0;
}

static bool HBitmapToPixels(HBITMAP hbm, std::vector<uint32_t>& px, int& w, int& h) {
    BITMAP bm = {};
    if (!GetObjectW(hbm, sizeof(bm), &bm)) {
        return false;
    }
    w = bm.bmWidth;
    h = bm.bmHeight;
    if (w <= 0 || h <= 0 || w > 512 || h > 512) {
        return false;
    }

    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = w;
    bi.bmiHeader.biHeight = -h;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    px.assign((size_t)w * h, 0);
    HDC hdc = GetDC(nullptr);
    int lines = GetDIBits(hdc, hbm, 0, h, px.data(), &bi, DIB_RGB_COLORS);
    ReleaseDC(nullptr, hdc);
    if (lines != h) {
        return false;
    }

    bool anyAlpha = false;
    bool needPremul = false;
    for (uint32_t p : px) {
        uint32_t a = p >> 24;
        uint32_t r = (p >> 16) & 255;
        uint32_t g = (p >> 8) & 255;
        uint32_t b = p & 255;
        if (a) anyAlpha = true;
        if (r > a || g > a || b > a) needPremul = true;
    }
    if (!anyAlpha) {
        for (auto& p : px) p |= 0xFF000000u;  // icon without alpha channel: opaque
    } else if (needPremul) {
        for (auto& p : px) {
            uint32_t a = p >> 24;
            uint32_t r = ((p >> 16) & 255) * a / 255;
            uint32_t g = ((p >> 8) & 255) * a / 255;
            uint32_t b = (p & 255) * a / 255;
            p = (a << 24) | (r << 16) | (g << 8) | b;
        }
    }
    return true;
}

// ---- Icons for packaged apps (Microsoft Store / MSIX) -----------------------
// For these apps, SIIGBF_ICONONLY usually returns the generic document icon.

// Packaged apps are identified by an AUMID like "Package_hash!App"
static bool IsPackagedId(const std::wstring& id) {
    return id.find(L'!') != std::wstring::npos && id.find(L'\\') == std::wstring::npos &&
           id.find(L'/') == std::wstring::npos && id.find(L':') == std::wstring::npos;
}

static std::wstring ItemString(IShellItem2* item, const wchar_t* canonicalName) {
    PROPERTYKEY key = {};
    if (FAILED(PSGetPropertyKeyFromName(canonicalName, &key))) {
        return L"";
    }
    std::wstring r;
    PWSTR str = nullptr;
    if (SUCCEEDED(item->GetString(key, &str)) && str) {
        r = str;
        CoTaskMemFree(str);
    }
    return r;
}

// Desktop app ids are usually "{GUID of known folder}\path\app.exe" or a full path. Serves as
// a fallback if the shell does not give the target property.
static std::wstring PathFromAppId(const std::wstring& id) {
    std::wstring path;
    if (!id.empty() && id[0] == L'{') {
        size_t end = id.find(L'}');
        if (end != std::wstring::npos) {
            GUID g;
            if (SUCCEEDED(CLSIDFromString(id.substr(0, end + 1).c_str(), &g))) {
                PWSTR base = nullptr;
                if (SUCCEEDED(SHGetKnownFolderPath(g, 0, nullptr, &base)) && base) {
                    path = base;
                    CoTaskMemFree(base);
                    if (end + 1 < id.size()) path += id.substr(end + 1);
                }
            }
        }
    } else if (id.size() > 3 && id[1] == L':' && id[2] == L'\\') {
        path = id;
    }
    return path;
}

// ---- Filter: uninstallers and documentation ----------------------------------------------
// Judged by what the shortcut REALLY runs (target and arguments), not by its name: a program
// such as "BCUninstaller" or "Revo Uninstaller" has "uninstall" in its name but is a real app.

enum UtilityKind { UtilNone = 0, UtilDoc = 1, UtilUninstaller = 2 };

static std::wstring LowerBaseName(const std::wstring& foldedPath) {
    size_t p = foldedPath.find_last_of(L"\\/");
    return p == std::wstring::npos ? foldedPath : foldedPath.substr(p + 1);
}

// `s` starts with `word` and the word ends there (end of text or a non-alphanumeric char).
static bool StartsWithWord(const std::wstring& s, const wchar_t* word) {
    const size_t n = wcslen(word);
    if (s.size() < n || s.compare(0, n, word) != 0) return false;
    return s.size() == n || !iswalnum(s[n]);
}

static bool EndsWithDocExt(std::wstring s) {
    while (!s.empty() && (s.back() == L'"' || s.back() == L' ')) s.pop_back();
    static const wchar_t* kDocExt[] = {L".url", L".chm", L".htm", L".html", L".mht",
                                       L".txt", L".rtf", L".pdf"};
    for (const wchar_t* e : kDocExt) {
        if (EndsWith(s, e)) return true;
    }
    return false;
}

// Executables that only uninstall: Inno Setup (unins000.exe), NSIS and others (uninstall.exe...).
static bool IsUninstallerExeName(const std::wstring& exe) {
    if (!EndsWith(exe, L".exe")) return false;
    const std::wstring stem = exe.substr(0, exe.size() - 4);
    static const wchar_t* kExact[] = {L"uninstall", L"uninst",   L"uninstal", L"uninstaller",
                                      L"unwise",    L"unwise32", L"un_a"};
    for (const wchar_t* e : kExact) {
        if (stem == e) return true;
    }
    // unins000, uninst64, uninstall32...: base word followed only by digits
    static const wchar_t* kBase[] = {L"unins", L"uninst", L"uninstall"};
    for (const wchar_t* b : kBase) {
        const size_t n = wcslen(b);
        if (stem.size() > n && stem.compare(0, n, b) == 0) {
            bool digits = true;
            for (size_t i = n; i < stem.size(); ++i) {
                if (!iswdigit(stem[i])) {
                    digits = false;
                    break;
                }
            }
            if (digits) return true;
        }
    }
    return false;
}

// "Uninstall X" / "Desinstalar X" style names (used only when the target is unknown).
static bool NameIsUninstallCommand(const std::wstring& fn) {
    static const wchar_t* kVerbs[] = {L"uninstall",      L"un-install",    L"desinstalar",
                                      L"desinstalacion", L"desinstalador", L"deinstallieren",
                                      L"desinstaller",   L"disinstalla"};
    for (const wchar_t* v : kVerbs) {
        if (StartsWithWord(fn, v)) return true;
    }
    return EndsWith(fn, L" uninstall") || EndsWith(fn, L" desinstalar");
}

static bool ArgsLookLikeUninstall(const std::wstring& foldedArgs) {
    return foldedArgs.find(L"uninstall") != std::wstring::npos ||
           foldedArgs.find(L"removeonly") != std::wstring::npos;
}

// Returns UtilNone, UtilDoc or UtilUninstaller.
static int ClassifyUtility(IShellItem* item, const std::wstring& name, const std::wstring& id) {
    if (IsPackagedId(id)) return UtilNone;  // Store apps are neither uninstallers nor documents

    const std::wstring fn = FoldString(name);
    const std::wstring fi = FoldString(id);

    std::wstring target, args;
    IShellItem2* item2 = nullptr;
    if (SUCCEEDED(item->QueryInterface(IID_PPV_ARGS(&item2))) && item2) {
        target = ItemString(item2, L"System.Link.TargetParsingPath");
        args = ItemString(item2, L"System.Link.Arguments");
        item2->Release();
    }
    if (target.empty()) target = PathFromAppId(id);

    const std::wstring ft = FoldString(target);
    const std::wstring fa = FoldString(args);
    const std::wstring exe = LowerBaseName(ft);

    // Documentation: a shortcut to a document or web page, or a "Readme"-style name
    if (EndsWithDocExt(fi) || EndsWithDocExt(ft) || EndsWithDocExt(fa)) return UtilDoc;
    static const wchar_t* kDocNames[] = {L"readme", L"read me", L"leeme", L"release notes",
                                         L"notas de la version"};
    for (const wchar_t* n : kDocNames) {
        if (StartsWithWord(fn, n)) return UtilDoc;
    }

    if (!ft.empty()) {
        // The target is known: it decides. Only things that really uninstall are hidden;
        // anything else (even with "uninstall" in the name) is a normal program.
        if (exe == L"msiexec.exe") return UtilUninstaller;
        if (IsUninstallerExeName(exe)) return UtilUninstaller;
        if (ArgsLookLikeUninstall(fa)) return UtilUninstaller;
        return UtilNone;
    }
    // Unknown target (for example advertised MSI shortcuts): only the imperative name counts.
    return NameIsUninstallCommand(fn) ? UtilUninstaller : UtilNone;
}


struct Pix {
    std::vector<uint32_t> px;
    int w = 0;
    int h = 0;
    bool ok = false;
    uint64_t hash = 0;
};

static uint64_t HashPixels(const std::vector<uint32_t>& px, int w, int h) {
    uint64_t hsh = 1469598103934665603ULL ^ ((uint64_t)(uint32_t)w << 32) ^ (uint64_t)(uint32_t)h;
    for (uint32_t p : px) {
        hsh ^= p;
        hsh *= 1099511628211ULL;
    }
    return hsh;
}

// Shell icon of an IShellItem. WOW64 redirection stays enabled: icon resolution can load shell
// handlers and system DLLs, and switching redirection off around that could leave a failed DLL
// load behind for the whole session. 64-bit-only System32 tools are covered by
// GetClassicIconFallback (below), which reads their icons from Sysnative paths with plain file
// APIs. Packaged (Store) apps take their logo from the package and are left untouched.
static bool GetShellItemPixels(IShellItem* item, SIIGBF flags, int size, Pix& out) {
    IShellItemImageFactory* fac = nullptr;
    if (FAILED(item->QueryInterface(IID_PPV_ARGS(&fac))) || !fac) {
        return false;
    }
    SIZE sz = {size, size};
    HBITMAP hbm = nullptr;
    bool ok = false;
    const HRESULT hr = fac->GetImage(sz, flags, &hbm);
    if (SUCCEEDED(hr) && hbm) {
        ok = HBitmapToPixels(hbm, out.px, out.w, out.h);
        DeleteObject(hbm);
    }
    fac->Release();
    out.ok = ok;
    if (ok) {
        out.hash = HashPixels(out.px, out.w, out.h);
    }
    return ok;
}

// Case-insensitive prefix test.
static bool StartsWithNoCase(const std::wstring& s, const std::wstring& prefix) {
    if (s.size() < prefix.size()) return false;
    for (size_t i = 0; i < prefix.size(); ++i) {
        if (towlower(s[i]) != towlower(prefix[i])) return false;
    }
    return true;
}

// The mod runs inside the 32-bit windhawk.exe tool process, where the WOW64 redirector maps
// "C:\Windows\System32" to "C:\Windows\SysWOW64". 64-bit-only tools in the real System32
// (mdsched.exe, voiceaccess.exe, ...) are therefore invisible by path. "Sysnative" is the
// WOW64 alias for the real System32 (only valid from a 32-bit process), so paths under
// "<Windows>\System32\" are rewritten to it.
static std::wstring NativeSystemPath(const std::wstring& path) {
    static const bool wow64 = [] {
        BOOL w = FALSE;
        return IsWow64Process(GetCurrentProcess(), &w) && w;
    }();
    if (!wow64 || path.empty()) return path;
    wchar_t win[MAX_PATH];
    UINT n = GetWindowsDirectoryW(win, MAX_PATH);
    if (n == 0 || n >= MAX_PATH) return path;
    const std::wstring prefix = std::wstring(win) + L"\\System32\\";
    if (StartsWithNoCase(path, prefix)) {
        return std::wstring(win) + L"\\Sysnative\\" + path.substr(prefix.size());
    }
    return path;
}

// True when the path is inside the Windows directory (the only place affected by the WOW64
// redirection, and where a path must be resolved with the redirection disabled instead).
static bool IsUnderWindowsDir(const std::wstring& path) {
    wchar_t win[MAX_PATH];
    UINT n = GetWindowsDirectoryW(win, MAX_PATH);
    if (n == 0 || n >= MAX_PATH) return false;
    return StartsWithNoCase(path, std::wstring(win) + L"\\");
}

// ---- Fallback icon sources (system image list) --------------------------------------------
// Used when IShellItemImageFactory fails (system tools, MSI-advertised shortcuts such as
// Node.js, shortcuts whose icon lives in an installer cache, etc.).

static const GUID kIidImageList = {0x46EB5926, 0x582E, 0x4017, {0x9F, 0xDF, 0xE8, 0x99, 0x8D, 0xAA, 0x09, 0x50}};

// HICON -> premultiplied BGRA. Handles icons with an alpha channel and legacy mask icons.
static bool HIconToPix(HICON hi, Pix& out) {
    ICONINFO ii = {};
    if (!hi || !GetIconInfo(hi, &ii)) return false;
    bool ok = false;
    if (ii.hbmColor) {
        BITMAP bm = {};
        if (GetObjectW(ii.hbmColor, sizeof(bm), &bm) && bm.bmWidth > 0 && bm.bmHeight > 0 &&
            bm.bmWidth <= 512 && bm.bmHeight <= 512) {
            const int w = bm.bmWidth, h = bm.bmHeight;
            BITMAPINFO bi = {};
            bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            bi.bmiHeader.biWidth = w;
            bi.bmiHeader.biHeight = -h;
            bi.bmiHeader.biPlanes = 1;
            bi.bmiHeader.biBitCount = 32;
            bi.bmiHeader.biCompression = BI_RGB;
            std::vector<uint32_t> px((size_t)w * h, 0);
            HDC hdc = GetDC(nullptr);
            bool got = GetDIBits(hdc, ii.hbmColor, 0, h, px.data(), &bi, DIB_RGB_COLORS) == h;
            if (got) {
                bool anyAlpha = false;
                for (uint32_t p : px) {
                    if (p >> 24) { anyAlpha = true; break; }
                }
                if (!anyAlpha) {
                    // Legacy icon: transparency comes from the AND mask.
                    std::vector<uint32_t> mk((size_t)w * h, 0);
                    bool haveMask = ii.hbmMask &&
                                    GetDIBits(hdc, ii.hbmMask, 0, h, mk.data(), &bi, DIB_RGB_COLORS) == h;
                    for (size_t i = 0; i < px.size(); ++i) {
                        const bool transparent = haveMask && (mk[i] & 0xFF) != 0;
                        px[i] = transparent ? 0u : (px[i] | 0xFF000000u);
                    }
                } else {
                    for (auto& p : px) {
                        uint32_t a = p >> 24;
                        if (a == 255) continue;
                        uint32_t r = ((p >> 16) & 255) * a / 255;
                        uint32_t g = ((p >> 8) & 255) * a / 255;
                        uint32_t b = (p & 255) * a / 255;
                        p = (a << 24) | (r << 16) | (g << 8) | b;
                    }
                }
                out.px = std::move(px);
                out.w = w;
                out.h = h;
                ok = true;
            }
            ReleaseDC(nullptr, hdc);
        }
    }
    if (ii.hbmColor) DeleteObject(ii.hbmColor);
    if (ii.hbmMask) DeleteObject(ii.hbmMask);
    return ok;
}

// Box-downscale by an integer factor so 256 px jumbo icons end up at 64 px.
static void DownscalePix(Pix& p, int factor) {
    if (factor <= 1) return;
    const int nw = p.w / factor, nh = p.h / factor;
    if (nw <= 0 || nh <= 0) return;
    std::vector<uint32_t> o((size_t)nw * nh);
    for (int y = 0; y < nh; ++y) {
        for (int x = 0; x < nw; ++x) {
            uint32_t a = 0, r = 0, g = 0, b = 0;
            for (int yy = 0; yy < factor; ++yy) {
                for (int xx = 0; xx < factor; ++xx) {
                    uint32_t v = p.px[(size_t)(y * factor + yy) * p.w + (x * factor + xx)];
                    a += v >> 24;
                    r += (v >> 16) & 255;
                    g += (v >> 8) & 255;
                    b += v & 255;
                }
            }
            const uint32_t n = (uint32_t)(factor * factor);
            o[(size_t)y * nw + x] = ((a / n) << 24) | ((r / n) << 16) | ((g / n) << 8) | (b / n);
        }
    }
    p.px = std::move(o);
    p.w = nw;
    p.h = nh;
}

// Icon from the system image list. `pidlOrPath` is a PIDL when isPidl, else a file path.
static bool GetSystemImageListIcon(const void* pidlOrPath, bool isPidl, Pix& out) {
    SHFILEINFOW sfi = {};
    UINT flags = SHGFI_SYSICONINDEX | (isPidl ? SHGFI_PIDL : 0);
    if (!SHGetFileInfoW((LPCWSTR)pidlOrPath, 0, &sfi, sizeof(sfi), flags)) return false;

    // JUMBO (256) first, then EXTRALARGE (48), then LARGE (32).
    static const int kLists[] = {SHIL_JUMBO, SHIL_EXTRALARGE, SHIL_LARGE};
    for (int shil : kLists) {
        IImageList* il = nullptr;
        if (FAILED(SHGetImageList(shil, kIidImageList, (void**)&il)) || !il) continue;
        HICON hi = nullptr;
        bool ok = SUCCEEDED(il->GetIcon(sfi.iIcon, ILD_TRANSPARENT, &hi)) && hi && HIconToPix(hi, out);
        if (hi) DestroyIcon(hi);
        il->Release();
        if (ok) {
            if (out.w > 64 && out.w % 64 == 0) DownscalePix(out, out.w / 64);
            out.ok = true;
            out.hash = HashPixels(out.px, out.w, out.h);
            return true;
        }
    }
    return false;
}

// True if the image has a meaningful amount of visible (non-transparent) pixels.
static bool HasVisiblePixels(const Pix& p) {
    if (!p.ok || p.px.empty()) return false;
    size_t vis = 0;
    for (uint32_t v : p.px) {
        if ((v >> 24) > 24) ++vis;
    }
    return vis * 50 >= p.px.size();  // at least 2% of the pixels
}

// Icon straight from the resource of an exe/dll/ico (hi-res, bypasses the shell cache).
static bool GetFileIconPix(const std::wstring& path, Pix& out) {
    if (path.empty()) return false;
    const std::wstring real = NativeSystemPath(path);
    HICON hi = nullptr;
    UINT id = 0;
    UINT n = PrivateExtractIconsW(real.c_str(), 0, 64, 64, &hi, &id, 1, 0);
    bool ok = n >= 1 && n != 0xFFFFFFFFu && hi && HIconToPix(hi, out);
    if (hi) DestroyIcon(hi);
    if (ok) {
        out.ok = true;
        out.hash = HashPixels(out.px, out.w, out.h);
    }
    return ok;
}

// Tries every alternative source for a desktop app. Each result must have visible pixels.
static bool GetClassicIconFallback(IShellItem* item, const std::wstring& target, Pix& out) {
    auto good = [&](bool got) {
        if (got && HasVisiblePixels(out)) return true;
        out = Pix();
        return false;
    };
    if (!target.empty() && good(GetFileIconPix(target, out))) return true;

    PIDLIST_ABSOLUTE pidl = nullptr;
    if (SUCCEEDED(SHGetIDListFromObject(item, &pidl)) && pidl) {
        bool ok = good(GetSystemImageListIcon(pidl, true, out));
        CoTaskMemFree(pidl);
        if (ok) return true;
    }
    const std::wstring realTarget = NativeSystemPath(target);
    if (!realTarget.empty() && good(GetSystemImageListIcon(realTarget.c_str(), false, out))) return true;
    if (good(GetShellItemPixels(item, (SIIGBF)(SIIGBF_ICONONLY | SIIGBF_BIGGERSIZEOK), 64, out))) return true;
    if (good(GetShellItemPixels(item, SIIGBF_RESIZETOFIT, 64, out))) return true;
    return false;
}

// Path of the small logo PNG for a packaged app (property System.Tile.SmallLogoPath)
static std::wstring GetTileLogoPath(IShellItem* item) {
    PROPERTYKEY key = {};
    if (FAILED(PSGetPropertyKeyFromName(L"System.Tile.SmallLogoPath", &key))) {
        return L"";
    }
    IShellItem2* item2 = nullptr;
    if (FAILED(item->QueryInterface(IID_PPV_ARGS(&item2))) || !item2) {
        return L"";
    }
    std::wstring r;
    PWSTR str = nullptr;
    if (SUCCEEDED(item2->GetString(key, &str)) && str) {
        r = str;
        CoTaskMemFree(str);
    }
    item2->Release();
    return r;
}

// Loads a PNG (or other image) with WIC as premultiplied BGRA, scaled to at most 64 px
static bool LoadImageFilePixels(IWICImagingFactory* wic,
                                const std::wstring& path,
                                std::vector<uint32_t>& px,
                                int& w,
                                int& h) {
    if (!wic) {
        return false;
    }
    IWICBitmapDecoder* dec = nullptr;
    IWICBitmapFrameDecode* frame = nullptr;
    IWICBitmapScaler* scaler = nullptr;
    IWICFormatConverter* conv = nullptr;
    bool ok = false;

    if (SUCCEEDED(wic->CreateDecoderFromFilename(path.c_str(), nullptr, GENERIC_READ,
                                                 WICDecodeMetadataCacheOnDemand, &dec)) &&
        dec && SUCCEEDED(dec->GetFrame(0, &frame)) && frame) {
        UINT fw = 0, fh = 0;
        frame->GetSize(&fw, &fh);
        if (fw > 0 && fh > 0 && fw <= 4096 && fh <= 4096) {
            IWICBitmapSource* src = frame;
            UINT tw = fw, th = fh;
            const UINT kMax = 64;
            if (fw > kMax || fh > kMax) {
                UINT nw = fw, nh = fh;
                if (fw >= fh) {
                    nw = kMax;
                    nh = std::max<UINT>(1, fh * kMax / fw);
                } else {
                    nh = kMax;
                    nw = std::max<UINT>(1, fw * kMax / fh);
                }
                if (SUCCEEDED(wic->CreateBitmapScaler(&scaler)) && scaler &&
                    SUCCEEDED(scaler->Initialize(frame, nw, nh, WICBitmapInterpolationModeFant))) {
                    src = scaler;
                    tw = nw;
                    th = nh;
                }
            }
            if (SUCCEEDED(wic->CreateFormatConverter(&conv)) && conv &&
                SUCCEEDED(conv->Initialize(src, GUID_WICPixelFormat32bppPBGRA,
                                           WICBitmapDitherTypeNone, nullptr, 0.0,
                                           WICBitmapPaletteTypeCustom))) {
                px.assign((size_t)tw * th, 0);
                if (SUCCEEDED(conv->CopyPixels(nullptr, tw * 4, (UINT)(px.size() * 4),
                                               (BYTE*)px.data()))) {
                    w = (int)tw;
                    h = (int)th;
                    ok = true;
                }
            }
        }
    }
    SafeRelease(conv);
    SafeRelease(scaler);
    SafeRelease(frame);
    SafeRelease(dec);
    return ok;
}

// ---- Desktop apps (shortcuts, exe, url files on the Desktop) ----
static std::wstring KnownFolderPath(REFKNOWNFOLDERID id);  // defined with the watcher

static bool GetFileIconPixAt(const std::wstring& path, int idx, Pix& out) {
    if (path.empty()) return false;
    const std::wstring real = NativeSystemPath(path);
    HICON hi = nullptr;
    UINT id = 0;
    UINT n = PrivateExtractIconsW(real.c_str(), idx, 64, 64, &hi, &id, 1, 0);
    bool ok = n >= 1 && n != 0xFFFFFFFFu && hi && HIconToPix(hi, out);
    if (hi) DestroyIcon(hi);
    if (ok) {
        out.ok = true;
        out.hash = HashPixels(out.px, out.w, out.h);
    }
    return ok;
}

// Icon of a Desktop entry read from the shortcut's own icon location / target, which avoids the
// shortcut arrow overlay that the shell adds to .lnk files.
static bool GetDesktopIcon(const std::wstring& path, Pix& out) {
    const std::wstring lp = LowerAscii(path);
    if (EndsWith(lp, L".exe")) return GetFileIconPixAt(path, 0, out);
    if (!EndsWith(lp, L".lnk")) return false;
    IShellLinkW* link = nullptr;
    if (FAILED(CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&link))) ||
        !link) {
        return false;
    }
    bool ok = false;
    IPersistFile* pf = nullptr;
    if (SUCCEEDED(link->QueryInterface(IID_PPV_ARGS(&pf))) && pf) {
        if (SUCCEEDED(pf->Load(path.c_str(), STGM_READ))) {
            wchar_t loc[MAX_PATH] = {};
            int idx = 0;
            link->GetIconLocation(loc, MAX_PATH, &idx);
            std::wstring file = loc;
            if (file.empty()) {
                wchar_t tgt[MAX_PATH] = {};
                WIN32_FIND_DATAW fd = {};
                if (SUCCEEDED(link->GetPath(tgt, MAX_PATH, &fd, SLGP_RAWPATH)) && tgt[0]) file = tgt;
                idx = 0;
            }
            if (!file.empty()) {
                wchar_t exp[MAX_PATH * 2] = {};
                DWORD n = ExpandEnvironmentStringsW(file.c_str(), exp, ARRAYSIZE(exp));
                if (n > 0 && n <= ARRAYSIZE(exp)) file = exp;
                ok = GetFileIconPixAt(file, idx, out);
            }
        }
        pf->Release();
    }
    link->Release();
    return ok;
}

static bool IsDesktopAppExt(const std::wstring& lowerName) {
    return EndsWith(lowerName, L".lnk") || EndsWith(lowerName, L".exe") || EndsWith(lowerName, L".url") ||
           EndsWith(lowerName, L".appref-ms");
}

static void CollectDesktopFiles(const std::wstring& dir, int depth, std::vector<std::wstring>& out) {
    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileW((dir + L"\\*").c_str(), &fd);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        if (out.size() >= 500) break;
        const std::wstring name = fd.cFileName;
        if (name == L"." || name == L"..") continue;
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) continue;  // desktop.ini etc.
        const std::wstring full = dir + L"\\" + name;
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (depth > 1 && !(fd.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)) {
                CollectDesktopFiles(full, depth - 1, out);
            }
            continue;
        }
        if (IsDesktopAppExt(LowerAscii(name))) out.push_back(full);
    } while (FindNextFileW(h, &fd));
    FindClose(h);
}

static std::wstring DesktopEntryName(const std::wstring& path) {
    size_t sl = path.find_last_of(L"\\/");
    std::wstring n = (sl == std::wstring::npos) ? path : path.substr(sl + 1);
    size_t dot = n.find_last_of(L'.');
    if (dot != std::wstring::npos && dot > 0) n.resize(dot);
    return n;
}

// Keeps shortcuts that launch something runnable; skips shortcuts to folders, documents or
// shell locations (This PC, Recycle Bin...).
// Target of a .lnk through IShellLink (used when the shell property comes back empty).
static std::wstring ResolveLnkTarget(const std::wstring& lnk) {
    std::wstring result;
    IShellLinkW* link = nullptr;
    if (FAILED(CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&link))) ||
        !link) {
        return result;
    }
    IPersistFile* pf = nullptr;
    if (SUCCEEDED(link->QueryInterface(IID_PPV_ARGS(&pf))) && pf) {
        if (SUCCEEDED(pf->Load(lnk.c_str(), STGM_READ))) {
            wchar_t tgt[MAX_PATH] = {};
            WIN32_FIND_DATAW fd = {};
            if (SUCCEEDED(link->GetPath(tgt, MAX_PATH, &fd, SLGP_RAWPATH)) && tgt[0]) {
                wchar_t exp[MAX_PATH * 2] = {};
                DWORD n = ExpandEnvironmentStringsW(tgt, exp, ARRAYSIZE(exp));
                result = (n > 0 && n <= ARRAYSIZE(exp)) ? std::wstring(exp) : std::wstring(tgt);
            }
        }
        pf->Release();
    }
    link->Release();
    return result;
}

static bool AcceptDesktopItem(IShellItem* item, const std::wstring& path, std::wstring& target) {
    const std::wstring lp = LowerAscii(path);
    target.clear();
    if (EndsWith(lp, L".exe")) {
        target = path;
        return true;
    }
    if (EndsWith(lp, L".url") || EndsWith(lp, L".appref-ms")) return true;
    IShellItem2* i2 = nullptr;
    if (SUCCEEDED(item->QueryInterface(IID_PPV_ARGS(&i2))) && i2) {
        target = ItemString(i2, L"System.Link.TargetParsingPath");
        i2->Release();
    }
    if (target.empty()) target = ResolveLnkTarget(path);
    if (target.empty()) return true;  // advertised / Store shortcuts: keep
    const std::wstring lt = LowerAscii(target);
    if (lt.size() >= 2 && lt[0] == L':' && lt[1] == L':') return false;  // shell locations (This PC...)
    const DWORD attr = GetFileAttributesW(NativeSystemPath(target).c_str());
    if (attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY)) return false;  // folders
    static const wchar_t* const kNotApps[] = {L".txt", L".pdf",  L".doc",  L".docx", L".xls", L".xlsx",
                                              L".ppt", L".pptx", L".png",  L".jpg",  L".jpeg", L".gif",
                                              L".mp3", L".mp4",  L".zip",  L".rar",  L".7z",  L".csv",
                                              L".md",  L".rtf",  L".html", L".htm"};
    for (const wchar_t* e : kNotApps) {
        if (EndsWith(lt, e)) return false;
    }
    return true;
}

static DWORD WINAPI IndexThreadProc(LPVOID param) {
    std::unique_ptr<IndexJob> job((IndexJob*)param);
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    struct Tmp {
        std::wstring folded;
        RawApp app;
        IShellItem* item;
    };
    std::vector<Tmp> tmp;

    std::unordered_set<std::wstring> seenNames;
    std::unordered_set<std::wstring> seenTargets;  // programs already found in the Start menu
    IShellItem* folder = nullptr;
    HRESULT hr = SHCreateItemFromParsingName(L"shell:AppsFolder", nullptr, IID_PPV_ARGS(&folder));
    if (SUCCEEDED(hr) && folder) {
        IEnumShellItems* en = nullptr;
        hr = folder->BindToHandler(nullptr, BHID_EnumItems, IID_PPV_ARGS(&en));
        if (SUCCEEDED(hr) && en) {
            IShellItem* it = nullptr;
            ULONG got = 0;
            while (en->Next(1, &it, &got) == S_OK && got == 1) {
                PWSTR dn = nullptr;
                PWSTR pn = nullptr;
                it->GetDisplayName(SIGDN_NORMALDISPLAY, &dn);
                it->GetDisplayName(SIGDN_PARENTRELATIVEPARSING, &pn);
                bool keep = dn && pn && *dn && *pn;
                std::wstring name = dn ? dn : L"";
                std::wstring id = pn ? pn : L"";
                if (dn) CoTaskMemFree(dn);
                if (pn) CoTaskMemFree(pn);

                if (keep && job->hideUtility && ClassifyUtility(it, name, id) != UtilNone) {
                    keep = false;
                }
                if (keep) {
                    std::wstring folded = FoldString(name);
                    if (!seenNames.insert(folded).second) {
                        keep = false;  // duplicate name
                    } else {
                        if (job->scanDesktop && !IsPackagedId(id)) {
                            IShellItem2* i2 = nullptr;
                            if (SUCCEEDED(it->QueryInterface(IID_PPV_ARGS(&i2))) && i2) {
                                std::wstring tg = ItemString(i2, L"System.Link.TargetParsingPath");
                                i2->Release();
                                if (tg.empty()) tg = PathFromAppId(id);
                                if (!tg.empty()) seenTargets.insert(FoldString(tg));
                            }
                        }
                        Tmp t;
                        t.folded = folded;
                        t.app.name = name;
                        t.app.id = id;
                        t.item = it;
                        tmp.push_back(std::move(t));
                    }
                }
                if (!keep) {
                    it->Release();
                }
                it = nullptr;
            }
            en->Release();
        }
        folder->Release();
    }

    // Desktop entries (user + public desktop): skipped when the Start menu already has the same
    // name or the same target program.
    if (job->scanDesktop) {
        std::vector<std::wstring> files;
        const GUID* kDirs[] = {&FOLDERID_Desktop, &FOLDERID_PublicDesktop};
        for (const GUID* g : kDirs) {
            const std::wstring dir = KnownFolderPath(*g);
            if (!dir.empty()) CollectDesktopFiles(dir, 2, files);
        }
        Wh_Log(L"Desktop scan: %d candidate files", (int)files.size());
        for (const std::wstring& path : files) {
            const std::wstring name = DesktopEntryName(path);
            if (name.empty()) continue;
            const std::wstring folded = FoldString(name);
            if (seenNames.count(folded)) {
                Wh_Log(L"Desktop skip (same name already indexed): %s", path.c_str());
                continue;
            }
            IShellItem* item = nullptr;
            if (FAILED(SHCreateItemFromParsingName(path.c_str(), nullptr, IID_PPV_ARGS(&item))) || !item) {
                Wh_Log(L"Desktop skip (shell item failed): %s", path.c_str());
                continue;
            }
            std::wstring target;
            if (!AcceptDesktopItem(item, path, target)) {
                Wh_Log(L"Desktop skip (not a program): %s", path.c_str());
                item->Release();
                continue;
            }
            seenNames.insert(folded);
            if (!target.empty()) seenTargets.insert(FoldString(target));
            Tmp t;
            t.folded = folded;
            t.app.name = name;
            t.app.id = path;
            t.app.desktop = true;
            t.item = item;
            tmp.push_back(std::move(t));
        }
    }

    if (job->scanDesktop) {
        int deskCount = 0;
        for (const auto& t : tmp) {
            if (t.app.desktop) ++deskCount;
        }
        Wh_Log(L"Desktop scan: %d entries added", deskCount);
    }

    std::sort(tmp.begin(), tmp.end(),
              [](const Tmp& a, const Tmp& b) { return a.folded < b.folded; });

    // 1) Send the app list (without icons) to the UI
    {
        auto* res = new IndexResult();
        res->gen = job->gen;
        res->apps.reserve(tmp.size());
        for (auto& t : tmp) res->apps.push_back(t.app);
        if (!PostMessageW(job->hwnd, WM_APP_INDEX, 0, (LPARAM)res)) {
            delete res;
        }
    }

    // 2) Load icons. Classic apps use the shell icon (ICONONLY). Packaged apps try, in order,
    //    ICONONLY, the normal shell tile and the app logo PNG; an image repeated across 2+
    //    packaged apps is the generic icon and is discarded.
    struct Shot {
        Pix a;  // ICONONLY
        Pix b;  // normal shell image
    };
    std::vector<Shot> shots(tmp.size());
    std::unordered_map<uint64_t, int> countA;
    std::unordered_map<uint64_t, int> countB;
    std::unordered_map<uint64_t, int> countC;  // classic apps: repeated image = generic icon
    for (size_t i = 0; i < tmp.size(); ++i) {
        if (job->haveIcons.count(tmp[i].app.id)) {
            continue;
        }
        if (!IsPackagedId(tmp[i].app.id)) {
            if (tmp[i].app.desktop) {
                Pix lp;
                if (GetDesktopIcon(tmp[i].app.id, lp) && HasVisiblePixels(lp)) {
                    shots[i].a = std::move(lp);
                    continue;
                }
            }
            if (GetShellItemPixels(tmp[i].item, SIIGBF_ICONONLY, 64, shots[i].a)) {
                ++countC[shots[i].a.hash];
            }
            continue;
        }
        if (GetShellItemPixels(tmp[i].item, SIIGBF_ICONONLY, 64, shots[i].a)) {
            ++countA[shots[i].a.hash];
        }
        if (GetShellItemPixels(tmp[i].item, SIIGBF_RESIZETOFIT, 64, shots[i].b)) {
            ++countB[shots[i].b.hash];
        }
    }

    IWICImagingFactory* wic = nullptr;
    for (size_t i = 0; i < tmp.size(); ++i) {
        const std::wstring& id = tmp[i].app.id;
        if (job->haveIcons.count(id)) {
            continue;
        }
        auto* ir = new IconResult();
        ir->gen = job->gen;
        ir->index = i;
        ir->w = 0;
        ir->h = 0;
        bool have = false;

        auto take = [&](Pix& p) {
            ir->px = std::move(p.px);
            ir->w = p.w;
            ir->h = p.h;
            have = true;
        };

        if (!IsPackagedId(id)) {
            Pix& a = shots[i].a;
            // The shell may return a blank or generic icon, so only trust the result
            // when it is visible and not repeated across 3+ apps.
            const bool suspicious = a.ok && (!HasVisiblePixels(a) || countC[a.hash] >= 3);
            if (a.ok && !suspicious) {
                take(a);
            } else {
                std::wstring target;
                IShellItem2* it2 = nullptr;
                if (SUCCEEDED(tmp[i].item->QueryInterface(IID_PPV_ARGS(&it2))) && it2) {
                    target = ItemString(it2, L"System.Link.TargetParsingPath");
                    it2->Release();
                }
                if (target.empty()) target = PathFromAppId(id);
                Pix f;
                if (GetClassicIconFallback(tmp[i].item, target, f)) {
                    take(f);
                } else if (a.ok) {
                    take(a);  // nothing better found: keep what the shell gave
                }
            }
        } else {
            Shot& s = shots[i];
            if (s.a.ok && countA[s.a.hash] < 2) {
                take(s.a);
            } else if (s.b.ok && countB[s.b.hash] < 2) {
                take(s.b);
            } else {
                std::wstring logo = GetTileLogoPath(tmp[i].item);
                if (!logo.empty() && GetFileAttributesW(logo.c_str()) != INVALID_FILE_ATTRIBUTES) {
                    if (!wic) {
                        CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
                                         IID_PPV_ARGS(&wic));
                    }
                    if (LoadImageFilePixels(wic, logo, ir->px, ir->w, ir->h)) {
                        have = true;
                    }
                }
                if (!have) {
                    Pix f;
                    PIDLIST_ABSOLUTE pidl = nullptr;
                    if (SUCCEEDED(SHGetIDListFromObject(tmp[i].item, &pidl)) && pidl) {
                        if (GetSystemImageListIcon(pidl, true, f)) {
                            take(f);
                        }
                        CoTaskMemFree(pidl);
                    }
                }
            }
        }

        if (!have || !PostMessageW(job->hwnd, WM_APP_ICON, 0, (LPARAM)ir)) {
            delete ir;
        }
    }
    SafeRelease(wic);

    for (auto& t : tmp) {
        t.item->Release();
    }

    PostMessageW(job->hwnd, WM_APP_INDEX_DONE, job->gen, 0);
    CoUninitialize();
    return 0;
}

// `refreshIcons` also reloads icons that are already cached (manual reindex).
static void StartIndex(bool refreshIcons = false) {
    if (g_indexing || !g_hwnd) {
        return;
    }
    g_indexing = true;
    g_lastIndexAt = NowSec();
    g_menuDirty = false;  // whatever changes from now on will set it again
    ++g_gen;

    auto* job = new IndexJob();
    job->hwnd = g_hwnd;
    job->gen = g_gen;
    job->hideUtility = g_cfg.hideUtility;
    job->scanDesktop = g_cfg.scanDesktop;
    for (const auto& a : g_apps) {
        if (!refreshIcons && !a.iconPx.empty()) job->haveIcons.insert(a.id);
    }

    HANDLE th = CreateThread(nullptr, 0, IndexThreadProc, job, 0, nullptr);
    if (!th) {
        delete job;
        g_indexing = false;
        g_menuDirty = true;  // could not index: retry next time
        return;
    }
    CloseHandle(th);
}

// Whether to reindex on opening, according to the "App index updates" setting:
//  - Automatic: only if the watcher saw changes, or after 10 minutes as a fallback for
//    Store apps that do not touch the Start menu folders.
//  - Every time it opens: always.
//  - Interval: once the chosen time has passed since the last reindex.
static bool ShouldReindexOnOpen() {
    double elapsed = NowSec() - g_lastIndexAt;
    switch (g_cfg.reindexMode) {
        case ReindexMode::Always:
            return true;
        case ReindexMode::Interval:
            return elapsed >= g_cfg.reindexIntervalSec;
        case ReindexMode::Auto:
        default:
            return g_menuDirty || elapsed >= kAutoSafetyRescanSec;
    }
}

// ===== Start menu watcher (change detection, Automatic mode) =====
// The two Start menu folders (all users and current user) are watched. Installers fire many
// events in a row and Windows needs a few seconds to register the shortcut, so the UI is only
// notified once the events stop arriving.

static std::wstring KnownFolderPath(REFKNOWNFOLDERID id) {
    std::wstring r;
    PWSTR p = nullptr;
    if (SUCCEEDED(SHGetKnownFolderPath(id, 0, nullptr, &p)) && p) {
        r = p;
        CoTaskMemFree(p);
    }
    return r;
}

static DWORD WINAPI WatchThreadProc(LPVOID param) {
    HWND hwnd = (HWND)param;
    const std::wstring dirs[4] = {KnownFolderPath(FOLDERID_CommonPrograms),
                                  KnownFolderPath(FOLDERID_Programs),
                                  KnownFolderPath(FOLDERID_Desktop),
                                  KnownFolderPath(FOLDERID_PublicDesktop)};
    const DWORD filter =
        FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_LAST_WRITE;
    const DWORD filterDesktop = FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME;

    HANDLE handles[5];
    DWORD n = 0;
    for (int di = 0; di < 4; ++di) {
        const std::wstring& d = dirs[di];
        if (d.empty()) continue;
        HANDLE h = FindFirstChangeNotificationW(d.c_str(), TRUE, di < 2 ? filter : filterDesktop);
        if (h == INVALID_HANDLE_VALUE) {
            continue;
        }
        handles[n++] = h;
    }
    const DWORD stopIdx = n;
    handles[n++] = g_watchStop;

    if (stopIdx == 0) {
        return 0;
    }

    for (;;) {
        DWORD w = WaitForMultipleObjects(n, handles, FALSE, INFINITE);
        if (w >= WAIT_OBJECT_0 + stopIdx) break;  // stop, or error
        FindNextChangeNotification(handles[w - WAIT_OBJECT_0]);

        // Debounce: wait until it goes quiet.
        bool stop = false;
        for (;;) {
            DWORD w2 = WaitForMultipleObjects(n, handles, FALSE, kWatchDebounceMs);
            if (w2 == WAIT_TIMEOUT) break;
            if (w2 >= WAIT_OBJECT_0 + stopIdx) {
                stop = true;
                break;
            }
            FindNextChangeNotification(handles[w2 - WAIT_OBJECT_0]);
        }
        if (stop) break;

        PostMessageW(hwnd, WM_APP_MENU_CHANGED, 0, 0);
    }

    for (DWORD i = 0; i < stopIdx; ++i) {
        FindCloseChangeNotification(handles[i]);
    }
    return 0;
}

static void StartWatcher() {
    if (g_watchThread || !g_hwnd) {
        return;
    }
    g_watchStop = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    if (!g_watchStop) {
        return;
    }
    g_watchThread = CreateThread(nullptr, 0, WatchThreadProc, g_hwnd, 0, nullptr);
    if (!g_watchThread) {
        CloseHandle(g_watchStop);
        g_watchStop = nullptr;
    }
}

static void StopWatcher() {
    if (g_watchStop) {
        SetEvent(g_watchStop);
    }
    if (g_watchThread) {
        WaitForSingleObject(g_watchThread, 3000);
        CloseHandle(g_watchThread);
        g_watchThread = nullptr;
    }
    if (g_watchStop) {
        CloseHandle(g_watchStop);
        g_watchStop = nullptr;
    }
}

// Automatic mode: with pending changes, reindex in the background instead of waiting for the
// bar to open, only while it is hidden (applying an index resets the selection).
static void MaybeReindexInBackground() {
    if (g_cfg.reindexMode == ReindexMode::Auto && g_menuDirty && !g_indexing &&
        g_vis == Vis::Hidden) {
        StartIndex();
    }
}

static std::wstring UsageKey(const std::wstring& id) {
    uint64_t h = 1469598103934665603ULL;
    for (wchar_t c : id) {
        h ^= (uint64_t)c;
        h *= 1099511628211ULL;
    }
    wchar_t hex[17];
    swprintf_s(hex, L"%016llx", (unsigned long long)h);
    return L"u" + CurrentUserSid() + L"_" + hex;
}

static void UpdateTargets(bool snap, bool followSelection);
static void MarkDirty();
static int DefaultSel();
static void ResetScroll();

static void ApplyIndex(IndexResult& r) {
    // Remember the selected app so a reindex while the bar is open does not reset the selection.
    std::wstring keepId;
    if (g_sel >= 0 && g_sel < (int)g_results.size()) keepId = g_apps[g_results[g_sel].app].id;

    std::unordered_map<std::wstring, size_t> old;
    for (size_t i = 0; i < g_apps.size(); ++i) {
        old[g_apps[i].id] = i;
    }
    std::vector<char> taken(g_apps.size(), 0);

    std::vector<AppEntry> next;
    next.reserve(r.apps.size());
    for (auto& ra : r.apps) {
        AppEntry a;
        a.name = ra.name;
        a.id = ra.id;
        a.desktop = ra.desktop;
        a.folded = FoldString(a.name);
        a.usageKey = UsageKey(a.id);
        a.uses = Wh_GetIntValue(a.usageKey.c_str(), 0);
        a.lastUsed = Wh_GetIntValue((a.usageKey + L"t").c_str(), 0);
        auto it = old.find(a.id);
        if (it != old.end()) {
            AppEntry& o = g_apps[it->second];
            a.iconW = o.iconW;
            a.iconH = o.iconH;
            a.iconPx = std::move(o.iconPx);
            a.bmp = o.bmp;
            o.bmp = nullptr;
            taken[it->second] = 1;
        }
        next.push_back(std::move(a));
    }
    for (size_t i = 0; i < g_apps.size(); ++i) {
        if (!taken[i]) SafeRelease(g_apps[i].bmp);
    }

    ReleaseResultLayouts();
    g_results.clear();
    AppendCommandEntries(next);
    g_apps.swap(next);
    g_detailsCache.clear();  // paths/versions may have changed

    RunSearch();
    g_sel = DefaultSel();
    for (size_t i = 0; i < g_results.size() && !keepId.empty(); ++i) {
        if (g_apps[g_results[i].app].id == keepId) {
            g_sel = (int)i;
            break;
        }
    }
    if (g_sel == DefaultSel()) ResetScroll();
    UpdateTargets(false, /*followSelection=*/true);
    MarkDirty();
}

// Manual reindex (footer button or Ctrl+R): re-reads the app list and reloads every icon.
static void ForceReindex() {
    if (g_indexing) return;
    StartIndex(true);
    MarkDirty();
}

// ===== Surface (DIB) and Direct2D / DirectWrite resources =====

typedef HRESULT(WINAPI* GetDpiForMonitor_t)(HMONITOR, int, UINT*, UINT*);

static double MonitorScale(HMONITOR mon) {
    static GetDpiForMonitor_t fn = [] {
        HMODULE m = LoadLibraryExW(L"shcore.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
        return m ? (GetDpiForMonitor_t)GetProcAddress(m, "GetDpiForMonitor") : nullptr;
    }();
    UINT dx = 96, dy = 96;
    if (fn && SUCCEEDED(fn(mon, 0 /*MDT_EFFECTIVE_DPI*/, &dx, &dy)) && dx > 0) {
        return dx / 96.0;
    }
    return 1.0;
}

static void DestroySurface() {
    if (g_memDC) {
        if (g_oldBmp) {
            SelectObject(g_memDC, g_oldBmp);
            g_oldBmp = nullptr;
        }
    }
    if (g_dib) {
        DeleteObject(g_dib);
        g_dib = nullptr;
    }
}

static const wchar_t* PickFontFamily() {
    bool ok = false;
    IDWriteFontCollection* col = nullptr;
    if (SUCCEEDED(g_dw->GetSystemFontCollection(&col, FALSE)) && col) {
        UINT32 idx = 0;
        BOOL exists = FALSE;
        if (SUCCEEDED(col->FindFamilyName(L"Segoe UI Variable Text", &idx, &exists)) && exists) {
            ok = true;
        }
        col->Release();
    }
    return ok ? L"Segoe UI Variable Text" : L"Segoe UI";
}

static IDWriteTextFormat* MakeFormat(const wchar_t* family, float size, DWRITE_FONT_WEIGHT weight,
                                     DWRITE_TEXT_ALIGNMENT align = DWRITE_TEXT_ALIGNMENT_LEADING) {
    IDWriteTextFormat* f = nullptr;
    g_dw->CreateTextFormat(family, nullptr, weight, DWRITE_FONT_STYLE_NORMAL,
                           DWRITE_FONT_STRETCH_NORMAL, size, L"en-us", &f);
    if (f) {
        f->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        f->SetTextAlignment(align);
        f->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
    }
    return f;
}

static void ReleaseFormats() {
    IDWriteTextFormat** fmts[] = {&g_fmtInput, &g_fmtTitle,      &g_fmtHint,     &g_fmtKey,     &g_fmtEmpty,
                                  &g_fmtSection, &g_fmtPanelTitle, &g_fmtPanelSub, &g_fmtPanelRow};
    for (auto** f : fmts) SafeRelease(*f);
    SafeRelease(g_ellipsis);
    SafeRelease(g_ellipsisSm);
}

static void RebuildFormats() {
    ReleaseFormats();
    if (!g_dw) {
        return;
    }
    const wchar_t* fam = PickFontFamily();
    const DWRITE_FONT_WEIGHT normal = DWRITE_FONT_WEIGHT_NORMAL;
    const DWRITE_FONT_WEIGHT semi = DWRITE_FONT_WEIGHT_SEMI_BOLD;

    g_fmtInput = MakeFormat(fam, Sc(22.f), normal);
    g_fmtTitle = MakeFormat(fam, Sc(15.f), normal);
    g_fmtHint = MakeFormat(fam, Sc(12.5f), normal, DWRITE_TEXT_ALIGNMENT_TRAILING);
    g_fmtKey = MakeFormat(fam, Sc(13.f), normal, DWRITE_TEXT_ALIGNMENT_CENTER);
    g_fmtEmpty = MakeFormat(fam, Sc(14.f), normal, DWRITE_TEXT_ALIGNMENT_CENTER);
    g_fmtSection = MakeFormat(fam, Sc(11.5f), semi);
    g_fmtPanelTitle = MakeFormat(fam, Sc(16.f), semi);
    g_fmtPanelSub = MakeFormat(fam, Sc(12.f), normal);
    g_fmtPanelRow = MakeFormat(fam, Sc(13.f), normal);

    // Long app names and paths are trimmed with an ellipsis instead of overflowing.
    const DWRITE_TRIMMING tr = {DWRITE_TRIMMING_GRANULARITY_CHARACTER, 0, 0};
    if (g_fmtTitle) {
        g_dw->CreateEllipsisTrimmingSign(g_fmtTitle, &g_ellipsis);
        if (g_ellipsis) g_fmtTitle->SetTrimming(&tr, g_ellipsis);
    }
    if (g_fmtPanelRow) {
        g_dw->CreateEllipsisTrimmingSign(g_fmtPanelRow, &g_ellipsisSm);
        if (g_ellipsisSm) {
            for (IDWriteTextFormat* f : {g_fmtPanelRow, g_fmtPanelTitle, g_fmtPanelSub}) {
                if (f) f->SetTrimming(&tr, g_ellipsisSm);
            }
        }
    }
}

// ===== Software acrylic =====
// The system acrylic (DWMWA_SYSTEMBACKDROP_TYPE) fills the whole window rectangle, which cannot
// be combined with a layered window whose rounded card and shadow are drawn per pixel by
// Direct2D. Instead the desktop is captured before showing, downscaled, blurred and tinted as
// the card's fill brush, with grain on top.

// Box sizes (odd) whose 3-pass composition approximates a Gaussian of standard deviation sigma.
static void BoxesForGauss(double sigma, int n, int* sizes) {
    double wIdeal = std::sqrt(12.0 * sigma * sigma / n + 1.0);
    int wl = (int)std::floor(wIdeal);
    if (wl % 2 == 0) wl--;
    if (wl < 1) wl = 1;
    int wu = wl + 2;
    double mIdeal = (12.0 * sigma * sigma - n * wl * wl - 4.0 * n * wl - 3.0 * n) / (-4.0 * wl - 4.0);
    int m = (int)std::lround(mIdeal);
    for (int i = 0; i < n; ++i) sizes[i] = (i < m) ? wl : wu;
}

// One box blur pass (radius r) over 8-bit BGRA, with replicated edges (so the edges do
// not darken). horiz=true scans rows; false scans columns.
static void BoxBlurPass(const uint8_t* src, uint8_t* dst, int w, int h, int r, bool horiz) {
    const int len = horiz ? w : h;
    const int lines = horiz ? h : w;
    const size_t stepPx = horiz ? 4 : (size_t)w * 4;
    const size_t stepLine = horiz ? (size_t)w * 4 : 4;
    const int div = 2 * r + 1;
    for (int l = 0; l < lines; ++l) {
        const uint8_t* s = src + (size_t)l * stepLine;
        uint8_t* d = dst + (size_t)l * stepLine;
        for (int c = 0; c < 3; ++c) {
            int sum = s[c] * r;  // positions -r..-1 (replicate the first pixel)
            for (int k = 0; k <= r; ++k) sum += s[(size_t)std::min(k, len - 1) * stepPx + c];
            for (int i = 0; i < len; ++i) {
                d[(size_t)i * stepPx + c] = (uint8_t)((sum + div / 2) / div);
                int add = std::min(i + r + 1, len - 1);
                int sub = std::max(i - r, 0);
                sum += s[(size_t)add * stepPx + c] - s[(size_t)sub * stepPx + c];
            }
        }
        for (int i = 0; i < len; ++i) d[(size_t)i * stepPx + 3] = 255;
    }
}

static void GaussianBlurBGRA(std::vector<uint32_t>& px, int w, int h, double sigma) {
    if (w <= 0 || h <= 0 || sigma < 0.45) return;
    int sizes[3];
    BoxesForGauss(sigma, 3, sizes);
    std::vector<uint32_t> tmp(px.size());
    for (int i = 0; i < 3; ++i) {
        int r = (sizes[i] - 1) / 2;
        if (r < 1) continue;
        BoxBlurPass((const uint8_t*)px.data(), (uint8_t*)tmp.data(), w, h, r, true);
        BoxBlurPass((const uint8_t*)tmp.data(), (uint8_t*)px.data(), w, h, r, false);
    }
}

// BGRA capture (w x h, alpha ignored) -> image reduced `factor` times, blurred and with
// saturation increased (satPct 100 = no change; the Windows acrylic uses 125). Opaque.
static void BuildBackdrop(const uint32_t* src, int w, int h, int factor, double sigmaPx, int satPct,
                          std::vector<uint32_t>& out, int& ow, int& oh) {
    factor = std::max(1, factor);
    ow = (w + factor - 1) / factor;
    oh = (h + factor - 1) / factor;
    out.assign((size_t)ow * oh, 0xFF000000u);
    for (int y = 0; y < oh; ++y) {
        for (int x = 0; x < ow; ++x) {
            unsigned b = 0, g = 0, r = 0, n = 0;
            const int y1 = std::min(h, (y + 1) * factor);
            const int x1 = std::min(w, (x + 1) * factor);
            for (int yy = y * factor; yy < y1; ++yy) {
                const uint32_t* row = src + (size_t)yy * w;
                for (int xx = x * factor; xx < x1; ++xx) {
                    uint32_t p = row[xx];
                    b += p & 0xFF;
                    g += (p >> 8) & 0xFF;
                    r += (p >> 16) & 0xFF;
                    ++n;
                }
            }
            if (!n) n = 1;
            out[(size_t)y * ow + x] =
                0xFF000000u | ((r / n) << 16) | ((g / n) << 8) | (b / n);
        }
    }
    GaussianBlurBGRA(out, ow, oh, sigmaPx / factor);
    if (satPct != 100) {
        const int sat = satPct * 256 / 100;
        for (auto& p : out) {
            int b = p & 0xFF, g = (p >> 8) & 0xFF, r = (p >> 16) & 0xFF;
            int lum = (54 * r + 183 * g + 19 * b) >> 8;
            r = std::clamp(lum + (((r - lum) * sat) >> 8), 0, 255);
            g = std::clamp(lum + (((g - lum) * sat) >> 8), 0, 255);
            b = std::clamp(lum + (((b - lum) * sat) >> 8), 0, 255);
            p = 0xFF000000u | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
        }
    }
}

static void WaitForCompositor() {
    typedef HRESULT(WINAPI * DwmFlush_t)();
    HMODULE m = LoadLibraryExW(L"dwmapi.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (m) {
        auto fn = (DwmFlush_t)GetProcAddress(m, "DwmFlush");
        if (fn) fn();
        FreeLibrary(m);
    }
}

static void ReleaseBackdropResources() {
    SafeRelease(g_backBrush);
    SafeRelease(g_backBmp);
}

static void ReleaseBackdrop() {
    ReleaseBackdropResources();
    std::vector<uint32_t>().swap(g_backPx);
    g_backW = g_backH = 0;
}

// Recipe for each effect: blur (DIP), saturation (%), tint and grain multiplier,
// white veil, Aurora gradient and border sheen strength.
struct EffectParams {
    double sigmaDip;
    int satPct;
    float tintMul;
    float noiseMul;
    float veil;
    bool glow;
    float rim;
};

static EffectParams GetEffectParams() {
    switch (g_cfg.effect) {
        case BgEffect::Mica:    return {70.0, 95, 1.35f, 0.2f, 0.00f, false, 1.0f};
        case BgEffect::Glass:   return {9.0, 150, 0.45f, 0.0f, 0.00f, false, 2.2f};
        case BgEffect::Frosted: return {42.0, 100, 0.90f, 0.7f, 0.10f, false, 1.0f};
        case BgEffect::Aurora:  return {30.0, 135, 0.85f, 0.32f, 0.00f, true, 1.2f};
        default:                return {30.0, 125, 1.00f, 0.4f, 0.00f, false, 1.0f};
    }
}

static double BlurFactor() {
    return 0.4 + g_cfg.blurPct * 0.012;  // 0 -> 0.4, 50 -> 1.0, 100 -> 1.6
}

// Base tint opacity: Opacity 70 -> 0.15 (a lot of background shows), 90 -> ~0.56, 100 -> 1.
static float AcrylicTintAlpha() {
    const float t = std::clamp((g_cfg.opacityPct - 70) / 30.f, 0.f, 1.f);
    return 0.15f + 0.85f * std::pow(t, 1.8f);
}

static float EffectTintAlpha() {
    return std::clamp(AcrylicTintAlpha() * GetEffectParams().tintMul, 0.f, 1.f);
}

// ---- Undocumented API (SetWindowCompositionAttribute + WCA_ACCENT_POLICY) ----
enum LvAccentState {
    LV_ACCENT_ACRYLICBLURBEHIND = 4,
};

struct LvAccentPolicy {
    int AccentState;
    int AccentFlags;
    DWORD GradientColor;  // ABGR: alpha = tint opacity
    DWORD AnimationId;
};

struct LvWinCompAttrData {
    int Attrib;  // 19 = WCA_ACCENT_POLICY
    PVOID pvData;
    SIZE_T cbData;
};

typedef BOOL(WINAPI* LvSetWindowCompositionAttribute_t)(HWND, LvWinCompAttrData*);

static HWND g_liveWnd = nullptr;                    // acrylic window (below g_hwnd)
static bool g_liveSupported = false;                // API present and Windows >= 1803
static LvSetWindowCompositionAttribute_t g_pSetWCA = nullptr;
static HWND g_livePanel = nullptr;                  // acrylic of the details panel
static bool g_liveWin11 = false;                    // Windows 11: corners rounded by DWM
typedef HRESULT(WINAPI* LvDwmSetWindowAttribute_t)(HWND, DWORD, LPCVOID, DWORD);
static LvDwmSetWindowAttribute_t g_pDwmSetAttr = nullptr;
static int g_liveRgnSize[2][2] = {};                // Windows 10: size of the last region
static int g_livePos[2][4] = {};                    // last x, y, w, h given to each window

// Windows 11: DWM rounds the acrylic windows; pref 1 = square, 2 = ~8 px, 3 = ~4 px.
static void LiveApplyCorners(DWORD pref) {
    HWND wins[2] = {g_liveWnd, g_livePanel};
    for (HWND h : wins) {
        if (h && g_pDwmSetAttr) g_pDwmSetAttr(h, 33 /*DWMWA_WINDOW_CORNER_PREFERENCE*/, &pref, sizeof(pref));
    }
}

static bool UseLive() {
    if (!g_liveSupported || !g_cfg.liveAcrylic || g_cfg.notch || FluidShell::FrameActive()) return false;
    return g_cfg.effect == BgEffect::Acrylic || g_cfg.effect == BgEffect::Glass ||
           g_cfg.effect == BgEffect::Frosted || g_cfg.effect == BgEffect::Aurora;
}

static bool WindowsBuildAtLeast(DWORD build) {
    typedef LONG(WINAPI * RtlGetVersion_t)(OSVERSIONINFOW*);
    HMODULE nt = GetModuleHandleW(L"ntdll.dll");
    auto fn = nt ? (RtlGetVersion_t)GetProcAddress(nt, "RtlGetVersion") : nullptr;
    if (!fn) return false;
    OSVERSIONINFOW vi = {};
    vi.dwOSVersionInfoSize = sizeof(vi);
    return fn(&vi) == 0 && vi.dwBuildNumber >= build;
}

static LRESULT CALLBACK LiveWndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_MOUSEACTIVATE:
            return MA_NOACTIVATE;
        case WM_NCHITTEST:
            return HTTRANSPARENT;  // the top window (g_hwnd) receives the input
    }
    return DefWindowProcW(h, m, w, l);
}

static HWND LiveCreateOne(HINSTANCE hInst) {
    // No WS_EX_LAYERED: DWM ignores regions and acrylic on layered windows.
    HWND h = CreateWindowExW(WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_NOACTIVATE,
                             L"SpotlightLauncherBackdrop", L"", WS_POPUP, 0, 0, 100, 100, nullptr,
                             nullptr, hInst, nullptr);
    if (h && g_pDwmSetAttr && g_liveWin11) {
        const DWORD pref = 2;  // DWMWCP_ROUND
        g_pDwmSetAttr(h, 33 /*DWMWA_WINDOW_CORNER_PREFERENCE*/, &pref, sizeof(pref));
        const DWORD none = 0xFFFFFFFE;  // DWMWA_COLOR_NONE: no system border
        g_pDwmSetAttr(h, 34 /*DWMWA_BORDER_COLOR*/, &none, sizeof(none));
    }
    return h;
}

static bool LiveCreate(HINSTANCE hInst) {
    HMODULE u = GetModuleHandleW(L"user32.dll");
    g_pSetWCA = u ? (LvSetWindowCompositionAttribute_t)GetProcAddress(u, "SetWindowCompositionAttribute")
                  : nullptr;
    g_liveSupported = g_pSetWCA && WindowsBuildAtLeast(17134);  // acrylic: 1803+
    if (!g_liveSupported) return false;

    g_liveWin11 = WindowsBuildAtLeast(22000);
    HMODULE dm = LoadLibraryExW(L"dwmapi.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    g_pDwmSetAttr = dm ? (LvDwmSetWindowAttribute_t)GetProcAddress(dm, "DwmSetWindowAttribute") : nullptr;

    WNDCLASSEXW wc = {};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = LiveWndProc;
    wc.hInstance = hInst;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);  // black = transparent for DWM
    wc.lpszClassName = L"SpotlightLauncherBackdrop";
    RegisterClassExW(&wc);

    g_liveWnd = LiveCreateOne(hInst);
    g_livePanel = LiveCreateOne(hInst);
    if (!g_liveWnd) {
        g_liveSupported = false;
        return false;
    }
    return true;
}

static void LiveDestroy() {
    if (g_livePanel) {
        DestroyWindow(g_livePanel);
        g_livePanel = nullptr;
    }
    if (g_liveWnd) {
        DestroyWindow(g_liveWnd);
        g_liveWnd = nullptr;
    }
}

// Tint + real-time acrylic.
static void LiveApplyAccent() {
    if (!g_pSetWCA) return;
    auto to8 = [](float v) { return (DWORD)std::clamp((int)std::lround(v * 255.f), 0, 255); };
    DWORD a = to8(EffectTintAlpha());
    if (a == 0) a = 1;  // acrylic does not support zero opacity
    LvAccentPolicy p = {};
    p.AccentState = LV_ACCENT_ACRYLICBLURBEHIND;
    p.AccentFlags = 0;
    p.GradientColor = (a << 24) | (to8(g_pal.bg.b) << 16) | (to8(g_pal.bg.g) << 8) | to8(g_pal.bg.r);
    LvWinCompAttrData d = {19 /*WCA_ACCENT_POLICY*/, &p, sizeof(p)};
    if (g_liveWnd) g_pSetWCA(g_liveWnd, &d);
    if (g_livePanel) g_pSetWCA(g_livePanel, &d);
}

static void LiveHide() {
    if (g_liveWnd && IsWindowVisible(g_liveWnd)) ShowWindow(g_liveWnd, SW_HIDE);
    if (g_livePanel && IsWindowVisible(g_livePanel)) ShowWindow(g_livePanel, SW_HIDE);
    memset(g_liveRgnSize, 0, sizeof(g_liveRgnSize));
    memset(g_livePos, 0, sizeof(g_livePos));
}

// Grain: kept separate from EnsureBackdropBrushes.
static void EnsureNoiseBrush() {
    if (g_noiseBrush || !g_rt) return;
    const int N = 128;
    std::vector<uint32_t> px((size_t)N * N);
    uint32_t s = 0x9E3779B9u;
    for (auto& p : px) {
        s ^= s << 13;
        s ^= s >> 17;
        s ^= s << 5;
        const uint32_t a = 22;  // base grain ~8.6%; each effect scales it with noiseMul
        const uint32_t c = (s & 0xFF) * a / 255;
        p = (a << 24) | (c << 16) | (c << 8) | c;
    }
    D2D1_BITMAP_PROPERTIES bp = D2D1::BitmapProperties(
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED), 96.f, 96.f);
    if (SUCCEEDED(g_rt->CreateBitmap(D2D1::SizeU(N, N), px.data(), N * 4, &bp, &g_noiseBmp)) && g_noiseBmp) {
        D2D1_BITMAP_BRUSH_PROPERTIES nbp = D2D1::BitmapBrushProperties(
            D2D1_EXTEND_MODE_WRAP, D2D1_EXTEND_MODE_WRAP, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
        g_rt->CreateBitmapBrush(g_noiseBmp, &nbp, nullptr, &g_noiseBrush);
    }
    if (!g_noiseBrush) SafeRelease(g_noiseBmp);
}



// Captures the desktop at (x, y, w, h) - screen pixels - and leaves it blurred in g_backPx.
// The window must be HIDDEN, or it would show up in the capture itself.
static bool CaptureBackdrop(int x, int y, int w, int h) {
    ReleaseBackdrop();
    if (w <= 0 || h <= 0) return false;
    HDC scr = GetDC(nullptr);
    if (!scr) {
        return false;
    }
    HDC mem = CreateCompatibleDC(scr);
    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = w;
    bi.bmiHeader.biHeight = -h;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    HBITMAP dib = mem ? CreateDIBSection(scr, &bi, DIB_RGB_COLORS, &bits, nullptr, 0) : nullptr;
    bool ok = false;
    if (mem && dib && bits) {
        HGDIOBJ old = SelectObject(mem, dib);
        // CAPTUREBLT also includes layered windows from other applications.
        ok = BitBlt(mem, 0, 0, w, h, scr, x, y, SRCCOPY | CAPTUREBLT) != 0;
        SelectObject(mem, old);
        if (ok) {
            GdiFlush();
            const EffectParams ep = GetEffectParams();
            const double sigmaPx = ep.sigmaDip * BlurFactor() * g_scale;
            const int factor = std::clamp((int)(sigmaPx / 3.0), 1, 4);
            BuildBackdrop((const uint32_t*)bits, w, h, factor, sigmaPx, ep.satPct, g_backPx, g_backW, g_backH);
        }
    }
    if (dib) DeleteObject(dib);
    if (mem) DeleteDC(mem);
    ReleaseDC(nullptr, scr);
    if (!ok) {
        ReleaseBackdrop();
        return false;
    }
    return true;
}

// Prepares the acrylic background for the next opening.
static void PrepareBackdrop() {
    if (g_cfg.effect == BgEffect::Solid || UseLive()) {
        ReleaseBackdrop();  // live acrylic: DWM blurs in real time, no capture needed
        return;
    }
    // DWM must stop compositing the window before capturing, or it shows up in the capture.
    if (IsWindowVisible(g_hwnd)) {
        ShowWindow(g_hwnd, SW_HIDE);
        WaitForCompositor();
    } else if (NowSec() - g_lastHide < 0.12) {
        WaitForCompositor();
    }
    CaptureBackdrop(g_winX, g_winY, g_bmpW, g_bmpH);
}

// Creates (if needed) the acrylic brushes in the current render target.
static bool EnsureBackdropBrushes() {
    if (!g_rt) return false;
    if (!g_backBrush && !g_backPx.empty() && g_backW > 0 && g_backH > 0 && g_bmpW > 0 && g_bmpH > 0) {
        D2D1_BITMAP_PROPERTIES bp = D2D1::BitmapProperties(
            D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED), 96.f, 96.f);
        HRESULT hr = g_rt->CreateBitmap(D2D1::SizeU((UINT32)g_backW, (UINT32)g_backH), g_backPx.data(),
                                        (UINT32)g_backW * 4, &bp, &g_backBmp);
        if (SUCCEEDED(hr) && g_backBmp) {
            D2D1_BITMAP_BRUSH_PROPERTIES bbp = D2D1::BitmapBrushProperties(
                D2D1_EXTEND_MODE_CLAMP, D2D1_EXTEND_MODE_CLAMP, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
            g_rt->CreateBitmapBrush(g_backBmp, &bbp, nullptr, &g_backBrush);
            if (g_backBrush) {
                // The downscaled image is stretched to cover the whole surface (screen px).
                D2D1_MATRIX_3X2_F m = D2D1::Matrix3x2F::Scale((float)g_bmpW / (float)g_backW,
                                                               (float)g_bmpH / (float)g_backH);
                g_backBrush->SetTransform(&m);
            }
        }
        if (!g_backBrush) SafeRelease(g_backBmp);
    }
    EnsureNoiseBrush();
    return g_backBrush != nullptr;
}

// Releases everything that depends on the render target (in case it has to be recreated)
static void ReleaseTarget() {
    ReleaseResultLayouts();
    for (auto& a : g_apps) {
        SafeRelease(a.bmp);
    }
    SafeRelease(g_brush);
    SafeRelease(g_matchBrush);
    SafeRelease(g_gradBrush);
    SafeRelease(g_glow1);
    SafeRelease(g_glow2);
    ReleaseBackdropResources();  // the pixels (g_backPx) are kept: the bitmap is recreated on draw
    SafeRelease(g_noiseBrush);
    SafeRelease(g_noiseBmp);
    SafeRelease(g_rt);
}

static bool EnsureTarget() {
    if (g_rt) {
        return true;
    }
    if (!g_d2d) {
        return false;
    }
    D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_DEFAULT,
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED), 96.f, 96.f,
        D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT);
    HRESULT hrRt = g_d2d->CreateDCRenderTarget(&props, &g_rt);
    if (FAILED(hrRt) || !g_rt) {
        return false;
    }
    g_rt->SetDpi(96.f, 96.f);
    g_rt->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 1), &g_brush);
    g_rt->CreateSolidColorBrush(g_pal.match, &g_matchBrush);
    return g_brush && g_matchBrush;
}

// Largest height (DIP) of the card; also the fixed height of the details panel.
static double ExpandedMaxH() {
    return kExpandedMinH;
}

static bool SelIsCmd() {
    return g_sel >= 0 && g_sel < (int)g_results.size() && g_results[g_sel].app >= 0 &&
           g_results[g_sel].app < (int)g_apps.size() && (g_apps[g_results[g_sel].app].isCmd || g_apps[g_results[g_sel].app].isWin);
}

// Height (DIP) of the expanded card: it follows its content (rows, calculator history, "No
// results") up to the maximum. The details panel always opens at the full height.
static double ExpandedH() {
    if (g_detailsOpen && !SelIsCmd()) return ExpandedMaxH();
    double content = 0.0;
    const size_t n = g_results.size();
    if (n > 0 && g_rowOff.size() == n + 1) {
        content = g_rowOff[n];  // rows including their section headers
    } else if (g_calcActive && !g_calcHist.empty()) {
        content = kSectionH + (double)g_calcHist.size() * kHistRowH;
    } else if (!g_tokens.empty() && !CalcShown()) {
        content = kEmptyRowH;
    }
    const double h = (double)kBarH + kFooterH + 2.0 * kListPad + HeroH() + content;
    return std::clamp(h, (double)kBarH + kEmptyRowH, ExpandedMaxH());
}

// Height (DIP) of the details panel; always matches the search bar.
static double DetailsPanelH() {
    return kExpandedMinH;
}

// Animated height (DIP) of the whole visible block.
static double BlockHeight() {
    return g_curH;
}

static bool EnsureSurface(double scale) {
    // The surface includes the details panel slot on the right (transparent while it is
    // closed), and is at least as tall as the panel.
    int newW = (int)std::ceil((kWidth + kPanelGap + kPanelW + 2 * kMargin) * scale);
    // The surface must be tall enough for the bar / details panel.
    const double maxH = std::max<double>(ExpandedH(), kExpandedMinH);
    int newH = (int)std::ceil((maxH + 2 * kMargin) * scale);
    bool scaleChanged = std::fabs(scale - g_scale) > 0.001;
    if (g_dib && !scaleChanged && newW == g_bmpW && newH == g_bmpH) {
        return true;
    }

    if (scaleChanged) {
        ReleaseResultLayouts();
    }
    g_scale = scale;
    g_bmpW = newW;
    g_bmpH = newH;

    if (!g_memDC) {
        g_memDC = CreateCompatibleDC(nullptr);
    }
    DestroySurface();

    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = g_bmpW;
    bi.bmiHeader.biHeight = -g_bmpH;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    g_dib = CreateDIBSection(nullptr, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (!g_dib) {
        return false;
    }
    g_oldBmp = SelectObject(g_memDC, g_dib);

    RebuildFormats();
    return true;
}

// ===== Layout / state animation =====

// Number of rows that fit in the visible rows area (the list scrolls for the rest).
static int VisibleRows() {
    const int n = (int)g_results.size();
    if (n == 0) return 0;
    // Available height for rows: expanded card minus the bar, the footer, the calculator card
    // and both paddings.
    const double rowsArea = ExpandedMaxH() - kBarH - kFooterH - 2 * kListPad - HeroH();
    int cap = (int)std::floor(rowsArea / kRowH);
    if (cap < 1) cap = 1;
    return std::min(n, cap);
}

// Height (DIP) of the rows area, including the section headers if any.
static double ListRowsHeight() {
    return VisibleRows() * kRowH + g_headerCount * kSectionH;
}

// Height (DIP) of the visible rows area: below the bar, above the footer, minus the padding.
static double ListViewportH() {
    return ExpandedH() - kBarH - kFooterH - 2 * kListPad - HeroH();
}

// Inverse of RowOffset(): given a vertical position `v` (DIP, in the same coordinates as
// g_rowOff) returns the fractional row position whose RowOffset equals `v`. It lets the
// keyboard scroll be computed in exact pixels and then be expressed in the row units used by
// the scroll animation (g_scrollPos / g_scrollTarget).
static double PosFromContentY(double v) {
    const int n = (int)g_results.size();
    if (n == 0 || g_rowOff.size() != (size_t)n + 1) return 0.0;
    if (v <= g_rowOff[0]) return 0.0;
    int i = (int)(std::upper_bound(g_rowOff.begin(), g_rowOff.begin() + n, (float)v) -
                  g_rowOff.begin()) - 1;
    i = std::clamp(i, 0, n - 1);
    const double a = g_rowOff[i];
    const double b = (i + 1 < n) ? g_rowOff[i + 1] : g_rowOff[i] + kRowH;
    const double f = (b > a) ? std::clamp((v - a) / (b - a), 0.0, 1.0) : 0.0;
    return i + f;
}

// Maximum scroll (DIP) that still shows the last row completely above the footer.
static double MaxScrollPx() {
    const int n = (int)g_results.size();
    if (n == 0 || g_rowOff.size() != (size_t)n + 1) return 0.0;
    return std::max(0.0, (double)g_rowOff[n] - ListViewportH());
}

// With the list growing upward the best match is the LAST row (next to the bar).
static int DefaultSel() {
    const int n = (int)g_results.size();
    return (g_flip && n > 0) ? n - 1 : 0;
}

static void ResetScroll() {
    if (!g_flip) {
        g_scrollTarget = 0;
        return;
    }
    const int n = (int)g_results.size();
    const int rows = VisibleRows();
    double m = std::max(0, n - rows);
    if (n > 0 && g_rowOff.size() == (size_t)n + 1) {
        m = std::max(m, PosFromContentY(MaxScrollPx() + g_rowOff[0]));
    }
    g_scrollTarget = m;
}

// `followSelection` is true only for keyboard selection changes (arrows, Tab, PageUp/Down);
// the mouse wheel and hover leave the scroll untouched.
static void UpdateTargets(bool snap, bool followSelection = true) {
    int rows = VisibleRows();
    // There are only two heights: bar alone, or expanded (fixed). While typing it is always
    // expanded, even without results ("No results" fills the list area).
    double h = kBarH;
    if (rows > 0 || !g_tokens.empty()) {
        h = ExpandedH();
    } else if (g_apps.empty() && !g_indexedOnce) {
        h += kEmptyRowH;
    }
    g_targetH = h;

    int n = (int)g_results.size();
    if (g_sel >= n) g_sel = std::max(0, n - 1);
    double maxScroll = std::max(0, n - rows);
    if (n > 0) {
        // Section headers consume space, so the last row may need a larger scroll than n - rows.
        maxScroll = std::max(maxScroll, PosFromContentY(MaxScrollPx() + g_rowOff[0]));
    }

    if (followSelection && rows > 0 && n > 0 && g_rowOff.size() == (size_t)n + 1) {
        // Scroll in exact pixels (rows have different heights due to headers): move just enough
        // to bring the selected row fully above the footer, without moving an already visible row.
        const double vp = ListViewportH();
        const double cur = RowOffset(g_scrollTarget) - g_rowOff[0];
        const int sec = g_results[g_sel].section;
        const int prevSec = g_sel > 0 ? g_results[g_sel - 1].section : 0;
        const bool hasHeader = sec != 0 && sec != prevSec;
        const double selTop = g_rowOff[g_sel] - (hasHeader ? kSectionH : 0.f);
        const double selBottom = g_rowOff[g_sel] + kRowH;
        double want = cur;
        if (selTop < cur) {
            want = selTop;            // above the view: align to the top (with its header)
        } else if (selBottom > cur + vp) {
            want = selBottom - vp;    // below the view: align bottom, exactly above the footer
        }
        want = std::clamp(want, 0.0, MaxScrollPx());
        if (std::fabs(want - cur) > 0.01) {
            g_scrollTarget = PosFromContentY(want + g_rowOff[0]);
            g_kbScroll = true;
        }
    }

    g_scrollTarget = std::clamp(g_scrollTarget, 0.0, maxScroll);
    g_selTarget = g_sel;

    // Details panel: there is only a panel if it is enabled and there is a selected app.
    if (n > 0 && g_sel >= 0 && g_sel < n) {
        g_panelAppId = g_apps[g_results[g_sel].app].id;
    }
    g_detailTarget = (g_detailsOpen && n > 0 && !SelIsCmd()) ? 1.0 : 0.0;

    if (snap) {
        g_curH = g_targetH;
        g_selPos = g_selTarget;
        g_scrollPos = g_scrollTarget;
        g_detailPos = g_detailTarget;
        g_curHV = 0.0;
        g_detailV = 0.0;
    }
}

static void StartFrameTimer() {
    if (!g_frameTimerOn && g_hwnd) {
        SetTimer(g_hwnd, TIMER_FRAME, 15, nullptr);
        g_frameTimerOn = true;
        g_lastFrame = NowSec();
    }
}

static void MarkDirty() {
    g_dirty = true;
    if (g_vis != Vis::Hidden) {
        StartFrameTimer();
    }
}

static void ResetBlink() {
    g_caretOn = true;
    if (g_hwnd && g_vis != Vis::Hidden) {
        SetTimer(g_hwnd, TIMER_BLINK, 530, nullptr);
    }
}

static void SetSelection(int idx) {
    int n = (int)g_results.size();
    if (n == 0) return;
    g_sel = std::clamp(idx, 0, n - 1);
    UpdateTargets(false, /*followSelection=*/true);
    MarkDirty();
}

static void SelectDelta(int d) {
    int n = (int)g_results.size();
    if (n == 0) return;
    int idx;
    if (d == 1 || d == -1) {
        idx = (g_sel + d + n) % n;  // wraps around
    } else {
        idx = std::clamp(g_sel + d, 0, n - 1);
    }
    SetSelection(idx);
}

static void OnTextChanged() {
    // The calculator is debounced: clear its state now so typing feels instant (app searches
    // update immediately) and only re-evaluate shortly after the user stops typing. That way
    // typing "pith" never flashes the value of "pi" on the way.
    g_calc = Calc::Result();
    g_calcDisplay.clear();
    g_calcActive = false;
    g_calcHistSel = -1;
    g_histScroll = 0;
    g_cmdArmed = -1;
    g_calcPending = true;
    if (g_hwnd) {
        KillTimer(g_hwnd, TIMER_CALC);
        SetTimer(g_hwnd, TIMER_CALC, 200, nullptr);
    }
    RunSearch();
    g_sel = DefaultSel();
    ResetScroll();
    UpdateTargets(false, /*followSelection=*/true);  // layout/selection follow the new results
    g_copiedAt = -1e9;  // typing again clears the calculator "Copied" flash
    if (g_hwnd) KillTimer(g_hwnd, TIMER_COPY);
    ResetBlink();
    MarkDirty();
}

// ===== Drawing =====

static void SetBrush(const D2D1_COLOR_F& c, float alphaMul = 1.f) {
    D2D1_COLOR_F k = c;
    k.a *= alphaMul;
    g_brush->SetColor(&k);
}

static void FillRR(float x0, float y0, float x1, float y1, float radius, const D2D1_COLOR_F& c,
                   float alphaMul = 1.f) {
    SetBrush(c, alphaMul);
    D2D1_ROUNDED_RECT rr = D2D1::RoundedRect(D2D1::RectF(x0, y0, x1, y1), radius, radius);
    g_rt->FillRoundedRectangle(&rr, g_brush);
}

static ID2D1Bitmap* EnsureIcon(AppEntry& a) {
    if (a.bmp) return a.bmp;
    if (a.iconPx.empty() || a.iconW <= 0 || a.iconH <= 0) return nullptr;
    D2D1_BITMAP_PROPERTIES bp = D2D1::BitmapProperties(
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED), 96.f, 96.f);
    g_rt->CreateBitmap(D2D1::SizeU((UINT32)a.iconW, (UINT32)a.iconH), a.iconPx.data(),
                       (UINT32)a.iconW * 4, &bp, &a.bmp);
    return a.bmp;
}

static IDWriteTextLayout* BuildTitleLayout(const AppEntry& a, float widthPx, float heightPx) {
    IDWriteTextLayout* l = nullptr;
    if (FAILED(g_dw->CreateTextLayout(a.name.c_str(), (UINT32)a.name.size(), g_fmtTitle, widthPx,
                                      heightPx, &l)) ||
        !l) {
        return nullptr;
    }
    std::vector<char> mask(a.folded.size(), 0);
    for (const auto& t : g_tokens) {
        ScoreToken(a.name, a.folded, t, &mask);
    }
    size_t i = 0;
    while (i < mask.size()) {
        if (mask[i]) {
            size_t j = i;
            while (j < mask.size() && mask[j]) ++j;
            DWRITE_TEXT_RANGE r = {(UINT32)i, (UINT32)(j - i)};
            l->SetFontWeight(DWRITE_FONT_WEIGHT_SEMI_BOLD, r);
            l->SetDrawingEffect(g_matchBrush, r);
            i = j;
        } else {
            ++i;
        }
    }
    return l;
}

static void DrawMagnifier(float cx, float cy) {
    SetBrush(g_pal.textDim);
    D2D1_ELLIPSE e = D2D1::Ellipse(D2D1::Point2F(cx - Sc(2.f), cy - Sc(2.f)), Sc(7.5f), Sc(7.5f));
    g_rt->DrawEllipse(&e, g_brush, Sc(2.f), g_roundStroke);
    g_rt->DrawLine(D2D1::Point2F(cx + Sc(3.4f), cy + Sc(3.4f)),
                   D2D1::Point2F(cx + Sc(9.f), cy + Sc(9.f)), g_brush, Sc(2.f), g_roundStroke);
}

// ===== Details panel: technical data, available actions and drawing =====
// Top-left corner (px) of the main panel inside the surface. The visible block is centered
// horizontally using the animated g_detailPos; vertically the bar stays at g_anchorTop unless
// the expanded card would not fit in the work area.
static void MainOrigin(float& ox, float& oy) {
    const double a = std::clamp(g_detailPos, 0.0, 1.0);
    const double innerW = kWidth + kPanelGap + kPanelW;
    const double compW = kWidth + a * (kPanelGap + kPanelW);
    // g_hAlign: 0.5 keeps the block centered; 0 / 1 keep the card (or the panel) glued to the edge.
    ox = (float)((kMargin + (innerW - compW) * g_hAlign) * g_scale);

    const double blockPx = BlockHeight() * g_scale;
    double cardTop;
    if (g_flip) {
        // Docked at the bottom: the bottom edge is fixed and the card grows upward.
        const double bottom = std::clamp(g_anchorBottom, g_workTop + blockPx,
                                         std::max(g_workTop + blockPx, g_workBottom));
        cardTop = bottom - blockPx;
    } else {
        cardTop = std::clamp(g_anchorTop, g_workTop, std::max(g_workTop, g_workBottom - blockPx));
    }
    oy = (float)(cardTop - g_winY);
}

// Vertical layout of the card (surface pixels). Normal: bar, list, footer (top to bottom).
// Flipped (docked at the bottom): footer, list, bar - the list grows upward from the bar.
struct Lay {
    float barTop, listTop, footerTop, listBottom, histBottom;
};

static Lay GetLay(float cy, float ch) {
    const float s = (float)g_scale;
    Lay L;
    if (g_flip) {
        const float cyb = cy + ch;
        const float top = cyb - (float)ExpandedH() * s;  // top of the fully expanded card
        L.barTop = cyb - kBarH * s;
        L.footerTop = top;
        L.listTop = top + kFooterH * s;
        L.listBottom = L.barTop - kListPad * s;
        L.histBottom = L.listBottom;
    } else {
        L.barTop = cy;
        L.listTop = cy + kBarH * s;
        L.footerTop = cy + (float)(ExpandedH() - kFooterH) * s;
        L.listBottom = std::min(cy + ch, L.footerTop - kListPad * s);
        L.histBottom = L.footerTop - kListPad * s;
    }
    return L;
}

// Where the first row is drawn. When flipped and there are few rows they hug the bar.
static float RowsOriginPx(const Lay& L) {
    const float s = (float)g_scale;
    float o = L.listTop + (kListPad + (float)HeroH()) * s;
    if (g_flip) {
        const double content = g_rowOff.empty() ? 0.0 : (double)g_rowOff.back();
        const double v = ListViewportH();
        if (content < v) o += (float)(v - content) * s;
    }
    return o;
}

// The details panel always has the full expanded height and shares the card's bottom edge.
static float PanelOriginY(float oy) {
    if (g_flip) return oy + (float)(g_curH - DetailsPanelH()) * (float)g_scale;
    return oy;
}

static std::wstring FormatSize(ULONGLONG b) {
    wchar_t buf[48];
    if (b < 1024) {
        swprintf_s(buf, L"%llu B", (unsigned long long)b);
    } else if (b < 1024ULL * 1024) {
        swprintf_s(buf, L"%.1f KB", b / 1024.0);
    } else {
        swprintf_s(buf, L"%.1f MB", b / (1024.0 * 1024.0));
    }
    return buf;
}

// Version and company from the .exe version resource
static void ReadVersionInfo(const std::wstring& path, std::wstring& version, std::wstring& company) {
    DWORD handle = 0;
    DWORD size = GetFileVersionInfoSizeW(path.c_str(), &handle);
    if (size == 0) {
        return;
    }
    std::vector<BYTE> buf(size);
    if (!GetFileVersionInfoW(path.c_str(), 0, size, buf.data())) {
        return;
    }

    VS_FIXEDFILEINFO* ffi = nullptr;
    UINT len = 0;
    if (VerQueryValueW(buf.data(), L"\\", (LPVOID*)&ffi, &len) && ffi && len >= sizeof(VS_FIXEDFILEINFO)) {
        wchar_t v[64];
        swprintf_s(v, L"%u.%u.%u.%u", (unsigned)HIWORD(ffi->dwFileVersionMS),
                   (unsigned)LOWORD(ffi->dwFileVersionMS), (unsigned)HIWORD(ffi->dwFileVersionLS),
                   (unsigned)LOWORD(ffi->dwFileVersionLS));
        version = v;
    }

    struct LangCp {
        WORD lang;
        WORD cp;
    };
    LangCp* tr = nullptr;
    UINT trLen = 0;
    if (VerQueryValueW(buf.data(), L"\\VarFileInfo\\Translation", (LPVOID*)&tr, &trLen) && tr &&
        trLen >= sizeof(LangCp)) {
        wchar_t sub[96];
        swprintf_s(sub, L"\\StringFileInfo\\%04x%04x\\CompanyName", (unsigned)tr[0].lang,
                   (unsigned)tr[0].cp);
        LPVOID val = nullptr;
        UINT vl = 0;
        if (VerQueryValueW(buf.data(), sub, &val, &vl) && val && vl > 1) {
            company = (const wchar_t*)val;
        }
    }
}

static AppDetails ComputeDetails(const AppEntry& a) {
    AppDetails d;
    d.packaged = IsPackagedId(a.id);

    std::wstring fullName;
    std::wstring installPath;

    IShellItem2* item = nullptr;
    std::wstring parse = a.desktop ? a.id : L"shell:AppsFolder\\" + a.id;
    if (SUCCEEDED(SHCreateItemFromParsingName(parse.c_str(), nullptr, IID_PPV_ARGS(&item))) && item) {
        d.target = ItemString(item, L"System.Link.TargetParsingPath");
        d.args = ItemString(item, L"System.Link.Arguments");
        if (d.packaged) {
            fullName = ItemString(item, L"System.AppUserModel.PackageFullName");
            installPath = ItemString(item, L"System.AppUserModel.PackageInstallPath");
        }
        item->Release();
    }
    if (d.packaged) {
        d.target.clear();  // MSIX apps are not launched or elevated by path
    } else if (d.target.empty()) {
        d.target = PathFromAppId(a.id);
    }
    // Shell namespace targets (e.g. File Explorer -> "::{...}This PC") are not files: hide the
    // path and the file-based actions instead of showing the raw GUID.
    if (d.target.size() >= 2 && d.target[0] == L':' && d.target[1] == L':') {
        d.target.clear();
    }

    std::wstring version, company, arch, sizeText, modified;

    if (!d.target.empty()) {
        // This 32-bit process has System32 redirected to SysWOW64: a 64-bit-only tool would
        // look missing and a dual-arch one would report the 32-bit copy's size and version.
        const std::wstring real = NativeSystemPath(d.target);
        WIN32_FILE_ATTRIBUTE_DATA fad = {};
        if (GetFileAttributesExW(real.c_str(), GetFileExInfoStandard, &fad) &&
            !(fad.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            d.canFile = true;
            d.isExe = EndsWith(FoldString(d.target), L".exe");
            // Elevation and the Properties dialog are handled by this 32-bit process, so they
            // see the path with WOW64 redirection. Offer them only when that path exists, or a
            // 64-bit-only tool (mdsched.exe, ...) would fail with "file not found".
            WIN32_FILE_ATTRIBUTE_DATA sad = {};
            d.canShell = GetFileAttributesExW(d.target.c_str(), GetFileExInfoStandard, &sad) &&
                         !(sad.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
            ReadVersionInfo(real, version, company);
            sizeText = FormatSize(((ULONGLONG)fad.nFileSizeHigh << 32) | fad.nFileSizeLow);
            modified = FormatFileTime(fad.ftLastWriteTime);
        } else {
            d.target.clear();  // path does not exist or is not a file
        }
    }

    if (d.packaged && !fullName.empty()) {
        // Name_Version_Architecture_ResourceId_PublisherId
        std::vector<std::wstring> parts;
        size_t start = 0;
        for (;;) {
            size_t p = fullName.find(L'_', start);
            if (p == std::wstring::npos) {
                parts.push_back(fullName.substr(start));
                break;
            }
            parts.push_back(fullName.substr(start, p - start));
            start = p + 1;
        }
        if (parts.size() >= 3) {
            version = parts[1];
            arch = (parts[2] == L"neutral") ? L"Neutral" : parts[2];
        }
    }

    auto add = [&](const wchar_t* label, const std::wstring& value, bool middle) {
        if (value.empty()) return;
        InfoRow r;
        r.label = label;
        r.value = value;
        r.middle = middle;
        d.rows.push_back(std::move(r));
    };
    add(L"Version", version, false);
    add(L"Company", company, false);
    add(L"Architecture", arch, false);
    add(L"Path", d.packaged ? installPath : d.target, true);
    if (d.packaged) add(L"ID", a.id, true);
    add(L"Size", sizeText, false);
    add(L"Modified", modified, false);
    add(L"Uses", std::to_wstring(a.uses), false);
    add(L"Last used", a.lastUsed > 0 ? FormatStamp(a.lastUsed) : (a.uses > 0 ? L"—" : L"Never"), false);
    return d;
}

static const AppDetails& GetDetails(const AppEntry& a) {
    auto it = g_detailsCache.find(a.id);
    if (it != g_detailsCache.end()) {
        return it->second;
    }
    return g_detailsCache.emplace(a.id, ComputeDetails(a)).first->second;
}

static bool ActionAvailable(int id, const AppEntry& a, const AppDetails& d) {
    switch (id) {
        case ACT_OPEN:
            return true;
        case ACT_ADMIN:
            return d.canShell && d.isExe;
        case ACT_LOCATION:
        case ACT_COPYPATH:
            return d.canFile;
        case ACT_PROPS:
            return d.canShell;
        case ACT_FORGET:
            return a.uses > 0;
    }
    return false;
}

static const ActionDef* FindAction(int id) {
    for (const ActionDef& ad : kActions) {
        if (ad.id == id) return &ad;
    }
    return nullptr;
}

// Actions available for an app, in the order they are shown. Returns how many.
static int BuildActions(const AppEntry& a, const AppDetails& d, int out[8]) {
    int n = 0;
    for (const ActionDef& ad : kActions) {
        if (n < 8 && ActionAvailable(ad.id, a, d)) out[n++] = ad.id;
    }
    return n;
}

// Shortens a text in the middle ("C:\Prog…\app.exe") so it fits in `widthPx`.
static std::wstring FitMiddle(const std::wstring& t, IDWriteTextFormat* fmt, float widthPx) {
    auto textW = [&](const std::wstring& str) -> float {
        IDWriteTextLayout* l = nullptr;
        if (FAILED(g_dw->CreateTextLayout(str.c_str(), (UINT32)str.size(), fmt, 10000.f, 100.f, &l)) ||
            !l) {
            return 0.f;
        }
        DWRITE_TEXT_METRICS m = {};
        l->GetMetrics(&m);
        l->Release();
        return m.widthIncludingTrailingWhitespace;
    };
    if (t.size() < 8 || textW(t) <= widthPx) {
        return t;
    }
    auto make = [&](size_t keep) {
        size_t head = keep / 3;  // more is kept at the end (the file name)
        size_t tail = keep - head;
        return t.substr(0, head) + L"…" + t.substr(t.size() - tail);
    };
    size_t lo = 2, hi = t.size() - 1, best = 2;
    while (lo <= hi) {
        size_t mid = (lo + hi) / 2;
        if (textW(make(mid)) <= widthPx) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return make(best);
}

static void DrawLabel(const std::wstring& str, IDWriteTextFormat* fmt, float x0, float y0, float x1,
                      float y1, const D2D1_COLOR_F& c, float alpha) {
    if (!fmt || str.empty()) return;
    SetBrush(c, alpha);
    D2D1_RECT_F r = D2D1::RectF(x0, y0, x1, y1);
    g_rt->DrawText(str.c_str(), (UINT32)str.size(), fmt, &r, g_brush);
}

// ---- Card, keycap and footer finish ----

// Linear gradient that fades from `c` (alpha `alpha`) to fully transparent, in unit coordinates
// from (0,0) to `end`; the caller stretches it over the target rectangle.
static void MakeFadeBrush(const D2D1_COLOR_F& c, float alpha, D2D1_POINT_2F end,
                          ID2D1LinearGradientBrush*& out) {
    if (out || !g_rt) return;
    D2D1_GRADIENT_STOP st[2] = {
        {0.f, D2D1::ColorF(c.r, c.g, c.b, alpha)},
        {1.f, D2D1::ColorF(c.r, c.g, c.b, 0.f)},
    };
    ID2D1GradientStopCollection* coll = nullptr;
    if (FAILED(g_rt->CreateGradientStopCollection(st, 2, &coll)) || !coll) return;
    g_rt->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(0, 0), end), coll,
                                    &out);
    coll->Release();
}

// Subtle sheen at the top of the card (dark themes only).
static void EnsureGradient() {
    if (!g_pal.light) MakeFadeBrush(g_pal.text, 0.095f, D2D1::Point2F(0, 1), g_gradBrush);
}

// Aurora effect: one accent gradient from each corner, fading towards the opposite one.
static void EnsureGlow() {
    MakeFadeBrush(g_pal.accent, g_pal.light ? 0.34f : 0.40f, D2D1::Point2F(1, 1), g_glow1);
    MakeFadeBrush(g_pal.accent2, g_pal.light ? 0.26f : 0.30f, D2D1::Point2F(1, 1), g_glow2);
}

// Each acrylic window is exactly the size of its card (no margins), so it does not depend on
// clipping with SetWindowRgn (DWM ignores it with acrylic). The rounded corners come from DWM on
// Windows 11 (DWMWCP_ROUND) and from a region as a fallback on Windows 10.
static void LivePlaceWindow(HWND wnd, int idx, int x, int y, int w, int h) {
    if (!wnd) return;
    if (w < 4 || h < 4) {
        if (IsWindowVisible(wnd)) ShowWindow(wnd, SW_HIDE);
        return;
    }
    if (!g_liveWin11 && (g_liveRgnSize[idx][0] != w || g_liveRgnSize[idx][1] != h)) {
        g_liveRgnSize[idx][0] = w;
        g_liveRgnSize[idx][1] = h;
        const int d = (int)std::lround(kRadius * (float)g_scale * 2.f);
        HRGN rgn = CreateRoundRectRgn(0, 0, w + 1, h + 1, d, d);
        SetWindowRgn(wnd, rgn, TRUE);  // the system takes ownership of rgn
    }
    // Acrylic windows are slow to move on some Windows 10 builds, so the window is only touched
    // when its rect changed, it is hidden, or something got between it and g_hwnd. Both acrylic
    // windows sit right below g_hwnd, in either order.
    const bool visible = IsWindowVisible(wnd) != FALSE;
    const HWND above = GetWindow(wnd, GW_HWNDPREV);
    const bool stacked = above == g_hwnd ||
                         ((above == g_liveWnd || above == g_livePanel) && above &&
                          GetWindow(above, GW_HWNDPREV) == g_hwnd);
    int* last = g_livePos[idx];
    if (visible && stacked && last[0] == x && last[1] == y && last[2] == w && last[3] == h) return;
    last[0] = x;
    last[1] = y;
    last[2] = w;
    last[3] = h;
    UINT flags = SWP_NOACTIVATE;
    if (!visible) flags |= SWP_SHOWWINDOW;
    if (stacked) flags |= SWP_NOZORDER;
    // insertAfter = g_hwnd  ->  ends up right BELOW g_hwnd.
    SetWindowPos(wnd, g_hwnd, x, y, w, h, flags);
}

// Call from Present(): keeps the acrylic window aligned with g_hwnd.
static void LiveSync() {
    if (!g_liveWnd) return;

    // Without WS_EX_LAYERED there is no global fade. The acrylic appears once the card is already
    // ~40% visible and disappears as soon as it starts closing (the top layer does fade fully).
    if (g_alpha < 0.4) {
        if (IsWindowVisible(g_liveWnd)) ShowWindow(g_liveWnd, SW_HIDE);
        if (g_livePanel && IsWindowVisible(g_livePanel)) ShowWindow(g_livePanel, SW_HIDE);
        return;
    }

    const float s = (float)g_scale;
    float cx = 0, cy = 0;
    MainOrigin(cx, cy);
    const int baseX = g_winX + (int)std::lround(g_offX);
    const int baseY = g_winY + (int)std::lround(g_offY);

    {
        double mx = cx, my = cy, mw = kWidth * s, mh = g_curH * s;
        if (std::fabs(g_animScale - 1.0) > 1e-4) {  // follow the "Pop up" scale
            const double sc = g_animScale;
            mx += mw * (1.0 - sc) / 2;
            my += mh * (1.0 - sc) / 2;
            mw *= sc;
            mh *= sc;
        }
        LivePlaceWindow(g_liveWnd, 0, baseX + (int)std::lround(mx), baseY + (int)std::lround(my),
                        (int)std::lround(mw), (int)std::lround(mh));
    }

    if (g_livePanel) {
        const float a = (float)std::clamp(g_detailPos, 0.0, 1.0);
        if (a > 0.02f) {
            const float ox = cx + (kWidth + kPanelGap + (1.f - a) * 14.f) * s;
            LivePlaceWindow(g_livePanel, 1, baseX + (int)std::lround(ox),
                            baseY + (int)std::lround(PanelOriginY(cy)),
                            (int)std::lround(kPanelW * s * a), (int)std::lround(DetailsPanelH() * s));
        } else if (IsWindowVisible(g_livePanel)) {
            ShowWindow(g_livePanel, SW_HIDE);
        }
    }
}

// Shadow that does NOT paint inside the card (otherwise it would cover the acrylic window below).
static void DrawShadowRing(float x, float y, float w, float h, float alpha) {
    if (!g_d2d || !g_rt) return;
    const float s = (float)g_scale;
    ID2D1RoundedRectangleGeometry* cardG = nullptr;
    if (FAILED(g_d2d->CreateRoundedRectangleGeometry(
            D2D1::RoundedRect(D2D1::RectF(x, y, x + w, y + h), kRadius * s, kRadius * s), &cardG)) ||
        !cardG) {
        return;
    }
    const int kLayers = 6;
    for (int k = kLayers; k >= 1; --k) {
        const float e = k * 2.f * s;
        const float a = g_pal.shadowAlpha * alpha * (1.f - (float)(k - 1) / kLayers);
        ID2D1RoundedRectangleGeometry* outerG = nullptr;
        ID2D1PathGeometry* ring = nullptr;
        ID2D1GeometrySink* sink = nullptr;
        if (SUCCEEDED(g_d2d->CreateRoundedRectangleGeometry(
                D2D1::RoundedRect(D2D1::RectF(x - e, y - e + 4 * s, x + w + e, y + h + e + 4 * s),
                                  kRadius * s + e, kRadius * s + e),
                &outerG)) && outerG &&
            SUCCEEDED(g_d2d->CreatePathGeometry(&ring)) && ring && SUCCEEDED(ring->Open(&sink)) && sink) {
            outerG->CombineWithGeometry(cardG, D2D1_COMBINE_MODE_EXCLUDE, nullptr, sink);
            sink->Close();
            SetBrush(D2D1::ColorF(0, 0, 0, 1), a);
            g_rt->FillGeometry(ring, g_brush);
        }
        SafeRelease(sink);
        SafeRelease(ring);
        SafeRelease(outerG);
    }
    cardG->Release();
}

// ---- Card shape: rounded rectangle with independent corners and optional concave flares ----

static ID2D1PathGeometry* MakeShapeGeo(float x, float y, float w, float h, float rTL, float rTR,
                                       float rBR, float rBL) {
    if (!g_d2d) return nullptr;
    ID2D1PathGeometry* g = nullptr;
    ID2D1GeometrySink* sink = nullptr;
    if (FAILED(g_d2d->CreatePathGeometry(&g)) || !g) return nullptr;
    if (FAILED(g->Open(&sink)) || !sink) {
        g->Release();
        return nullptr;
    }
    auto arc = [&](float px, float py, float r) {
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(px, py), D2D1::SizeF(r, r), 0.f,
                                      D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    };
    sink->BeginFigure(D2D1::Point2F(x + rTL, y), D2D1_FIGURE_BEGIN_FILLED);
    sink->AddLine(D2D1::Point2F(x + w - rTR, y));
    if (rTR > 0.f) arc(x + w, y + rTR, rTR);
    sink->AddLine(D2D1::Point2F(x + w, y + h - rBR));
    if (rBR > 0.f) arc(x + w - rBR, y + h, rBR);
    sink->AddLine(D2D1::Point2F(x + rBL, y + h));
    if (rBL > 0.f) arc(x, y + h - rBL, rBL);
    sink->AddLine(D2D1::Point2F(x, y + rTL));
    if (rTL > 0.f) arc(x + rTL, y, rTL);
    sink->EndFigure(D2D1_FIGURE_END_CLOSED);
    sink->Close();
    sink->Release();
    return g;
}

// Adds a concave "spandrel" (A -> B -> C, closed by an arc back to A) to `base` and returns the union.
static ID2D1PathGeometry* AddFlare(ID2D1PathGeometry* base, float ax, float ay, float bx, float by,
                                   float cx2, float cy2, D2D1_SWEEP_DIRECTION dir, float r) {
    if (!base || !g_d2d) return base;
    ID2D1PathGeometry* fl = nullptr;
    ID2D1GeometrySink* fs = nullptr;
    if (FAILED(g_d2d->CreatePathGeometry(&fl)) || !fl) return base;
    if (FAILED(fl->Open(&fs)) || !fs) {
        fl->Release();
        return base;
    }
    fs->BeginFigure(D2D1::Point2F(ax, ay), D2D1_FIGURE_BEGIN_FILLED);
    fs->AddLine(D2D1::Point2F(bx, by));
    fs->AddLine(D2D1::Point2F(cx2, cy2));
    fs->AddArc(D2D1::ArcSegment(D2D1::Point2F(ax, ay), D2D1::SizeF(r, r), 0.f, dir, D2D1_ARC_SIZE_SMALL));
    fs->EndFigure(D2D1_FIGURE_END_CLOSED);
    fs->Close();
    fs->Release();

    ID2D1PathGeometry* out = nullptr;
    ID2D1GeometrySink* os = nullptr;
    ID2D1PathGeometry* result = base;
    if (SUCCEEDED(g_d2d->CreatePathGeometry(&out)) && out) {
        if (SUCCEEDED(out->Open(&os)) && os) {
            HRESULT hr = base->CombineWithGeometry(fl, D2D1_COMBINE_MODE_UNION, nullptr, os);
            os->Close();
            os->Release();
            if (SUCCEEDED(hr)) {
                base->Release();
                result = out;
                out = nullptr;
            }
        }
        if (out) out->Release();
    }
    fl->Release();
    return result;
}

// Sides that are flat (notch mode): 1 top, 2 bottom, 4 left, 8 right; 16 = add concave flares.
// The details panel sits beside the card, so it only inherits the top / bottom / right sides.
static int CardFlags(bool panel) {
    int f = 0;
    if (g_flatTop) f |= 1;
    if (g_flatBottom) f |= 2;
    if (!panel && g_flatLeft) f |= 4;
    if (g_flatRight && (panel || g_detailPos < 0.5)) f |= 8;
    if (!panel) f |= 16;
    return f;
}

static void DrawGlow(ID2D1Geometry* geo, float x, float y, float w, float h, float alpha) {
    EnsureGlow();
    if (g_glow1) {
        g_glow1->SetStartPoint(D2D1::Point2F(x, y));
        g_glow1->SetEndPoint(D2D1::Point2F(x + w, y + h));
        g_glow1->SetOpacity(alpha);
        g_rt->FillGeometry(geo, g_glow1);
    }
    if (g_glow2) {
        g_glow2->SetStartPoint(D2D1::Point2F(x + w, y + h));
        g_glow2->SetEndPoint(D2D1::Point2F(x, y));
        g_glow2->SetOpacity(alpha);
        g_rt->FillGeometry(geo, g_glow2);
    }
}

// Card: shadow, body (live DWM acrylic or captured effect), sheen, optional border and inner edge.
static void DrawCard(float x, float y, float w, float h, float alpha, int flags = 0) {
    const float s = (float)g_scale;
    const bool live = UseLive();
    const float R = std::max(0.f, std::min(kRadius * s, std::min(w, h) / 2));
    const bool fT = (flags & 1) != 0, fB = (flags & 2) != 0, fL = (flags & 4) != 0, fR = (flags & 8) != 0;
    const float rTL = (fT || fL) ? 0.f : R;
    const float rTR = (fT || fR) ? 0.f : R;
    const float rBR = (fB || fR) ? 0.f : R;
    const float rBL = (fB || fL) ? 0.f : R;

    ID2D1PathGeometry* shape = MakeShapeGeo(x, y, w, h, rTL, rTR, rBR, rBL);
    ID2D1PathGeometry* fillG = MakeShapeGeo(x, y, w, h, rTL, rTR, rBR, rBL);
    if (!shape || !fillG) {
        SafeRelease(shape);
        SafeRelease(fillG);
        return;
    }
    const int nFlat = (fT ? 1 : 0) + (fB ? 1 : 0) + (fL ? 1 : 0) + (fR ? 1 : 0);
    if ((flags & 16) && nFlat == 1 && R > 0.5f) {
        const D2D1_SWEEP_DIRECTION cw = D2D1_SWEEP_DIRECTION_CLOCKWISE;
        const D2D1_SWEEP_DIRECTION ccw = D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE;
        if (fT) {
            fillG = AddFlare(fillG, x - R, y, x, y, x, y + R, ccw, R);
            fillG = AddFlare(fillG, x + w + R, y, x + w, y, x + w, y + R, cw, R);
        } else if (fB) {
            fillG = AddFlare(fillG, x - R, y + h, x, y + h, x, y + h - R, cw, R);
            fillG = AddFlare(fillG, x + w + R, y + h, x + w, y + h, x + w, y + h - R, ccw, R);
        } else if (fL) {
            fillG = AddFlare(fillG, x, y - R, x, y, x + R, y, cw, R);
            fillG = AddFlare(fillG, x, y + h + R, x, y + h, x + R, y + h, ccw, R);
        } else if (fR) {
            fillG = AddFlare(fillG, x + w, y - R, x + w, y, x + w - R, y, ccw, R);
            fillG = AddFlare(fillG, x + w, y + h + R, x + w, y + h, x + w - R, y + h, cw, R);
        }
    }

    auto fillShape = [&](const D2D1_COLOR_F& c, float a) {
        SetBrush(c, a);
        g_rt->FillGeometry(fillG, g_brush);
    };

    if (!g_cfg.shadow) {
        // flat: no shadow
    } else if (live) {
        DrawShadowRing(x, y, w, h, alpha);
    } else {
        D2D1_COLOR_F black = D2D1::ColorF(0, 0, 0, 1);
        static const int kShadowLayers = 6;
        for (int k = kShadowLayers; k >= 1; --k) {
            float e = k * 2.0f * s;
            float a = g_pal.shadowAlpha * alpha * (1.0f - (float)(k - 1) / kShadowLayers);
            FillRR(x - e, y - e + 4 * s, x + w + e, y + h + e + 4 * s, R + e, black, a);
        }
    }

    const EffectParams ep = GetEffectParams();
    const bool solid = g_cfg.effect == BgEffect::Solid;
    const D2D1_COLOR_F white = D2D1::ColorF(1.f, 1.f, 1.f, 1.f);

    if (live) {
        // DWM provides the background and tint in g_liveWnd. Only a nearly invisible layer goes
        // here (alpha ~3/255) so that this window keeps receiving the mouse over the card.
        fillShape(D2D1::ColorF(0, 0, 0, 1), 0.012f);
        if (ep.veil > 0.f) fillShape(white, ep.veil * alpha);
        if (ep.glow) DrawGlow(fillG, x, y, w, h, alpha);
        if (g_cfg.effect != BgEffect::Acrylic) {  // DWM's acrylic already has its own grain
            EnsureNoiseBrush();
            if (g_noiseBrush && ep.noiseMul > 0.f) {
                g_noiseBrush->SetOpacity(std::min(1.f, alpha * ep.noiseMul));
                g_rt->FillGeometry(fillG, g_noiseBrush);
            }
        }
    } else if (!solid && EnsureBackdropBrushes()) {
        g_backBrush->SetOpacity(alpha);
        g_rt->FillGeometry(fillG, g_backBrush);
        if (ep.veil > 0.f) fillShape(white, ep.veil * alpha);
        D2D1_COLOR_F tint = g_pal.bg;
        tint.a = EffectTintAlpha();
        fillShape(tint, alpha);
        if (ep.glow) DrawGlow(fillG, x, y, w, h, alpha);
        if (g_noiseBrush && ep.noiseMul > 0.f) {
            g_noiseBrush->SetOpacity(std::min(1.f, alpha * ep.noiseMul));
            g_rt->FillGeometry(fillG, g_noiseBrush);
        }
    } else {
        D2D1_COLOR_F c = g_pal.bg;
        if (solid) c.a = 1.f;
        fillShape(c, alpha);
    }

    if (!g_cfg.borderless) {
        EnsureGradient();
        if (g_gradBrush) {
            g_gradBrush->SetStartPoint(D2D1::Point2F(x, y));
            g_gradBrush->SetEndPoint(D2D1::Point2F(x, y + std::max(1.f, h * 0.6f)));
            g_gradBrush->SetOpacity(std::min(1.f, alpha * ep.rim));
            g_rt->FillGeometry(shape, g_gradBrush);
        }

        SetBrush(g_pal.border, alpha);
        if (ID2D1PathGeometry* o = MakeShapeGeo(x + 0.5f, y + 0.5f, w - 1.f, h - 1.f,
                                                std::max(0.f, rTL - 0.5f), std::max(0.f, rTR - 0.5f),
                                                std::max(0.f, rBR - 0.5f), std::max(0.f, rBL - 0.5f))) {
            g_rt->DrawGeometry(o, g_brush, 1.f);
            o->Release();
        }

        const bool dark = !g_pal.light;
        SetBrush(white, std::min(1.f, (dark ? 0.06f : 0.55f) * ep.rim) * alpha);
        if (ID2D1PathGeometry* in = MakeShapeGeo(x + 1.5f, y + 1.5f, w - 3.f, h - 3.f,
                                                 std::max(0.f, rTL - 1.5f), std::max(0.f, rTR - 1.5f),
                                                 std::max(0.f, rBR - 1.5f), std::max(0.f, rBL - 1.5f))) {
            g_rt->DrawGeometry(in, g_brush, 1.f);
            in->Release();
        }
    }

    shape->Release();
    fillG->Release();
}


static float TextWidth(const wchar_t* txt, IDWriteTextFormat* fmt) {
    if (!fmt || !txt || !*txt) return 0.f;
    IDWriteTextLayout* l = nullptr;
    if (FAILED(g_dw->CreateTextLayout(txt, (UINT32)wcslen(txt), fmt, 10000.f, 100.f, &l)) || !l) {
        return 0.f;
    }
    DWRITE_TEXT_METRICS m = {};
    l->GetMetrics(&m);
    l->Release();
    return m.widthIncludingTrailingWhitespace;
}

static float KeycapWidth(const wchar_t* txt) {
    const float s = (float)g_scale;
    return std::max(24 * s, TextWidth(txt, g_fmtKey) + 14 * s);
}

// Keycap ending at xRight; returns its left x.
static float DrawKeycap(const wchar_t* txt, float xRight, float yMid) {
    const float s = (float)g_scale;
    const float capH = 22 * s;
    const float x0 = xRight - KeycapWidth(txt);
    FillRR(x0, yMid - capH / 2, xRight, yMid + capH / 2, 6 * s, g_pal.keycap);
    DrawLabel(txt, g_fmtKey, x0, yMid - capH / 2, xRight, yMid + capH / 2, g_pal.textDim, 1.f);
    return x0;
}

// Footer hint ("Label [key][key]") ending at xRight; returns its left x.
static float DrawHint(const wchar_t* label, const wchar_t* const* keys, int nKeys, float xRight,
                      float yMid) {
    const float s = (float)g_scale;
    float x = xRight;
    for (int i = nKeys - 1; i >= 0; --i) {
        x = DrawKeycap(keys[i], x, yMid) - 4 * s;
    }
    const float labelRight = x - 4 * s;
    const float lw = TextWidth(label, g_fmtHint);
    DrawLabel(label, g_fmtHint, labelRight - lw - 4 * s, yMid - 12 * s, labelRight, yMid + 12 * s,
              g_pal.textDim, 1.f);
    return labelRight - lw;
}

// Width of a hint as drawn by DrawHint, used to size the clickable footer button.
static float HintWidth(const wchar_t* label, const wchar_t* const* keys, int nKeys) {
    const float s = (float)g_scale;
    float w = 4 * s + TextWidth(label, g_fmtHint);
    for (int i = 0; i < nKeys; ++i) w += KeycapWidth(keys[i]) + 4 * s;
    return w;
}

// Rectangle (surface pixels) of the footer reindex button: refresh icon + label + shortcut.
static D2D1_RECT_F ReindexButtonRect(float cx, float footerTop) {
    const float s = (float)g_scale;
    const float x0 = cx + 12 * s;
    const float w = 32 * s + HintWidth(kTxtReindex, kReindexKeys, 2) + 6 * s;
    return D2D1::RectF(x0, footerTop + 5 * s, x0 + w, footerTop + (kFooterH - 5) * s);
}

// Circular arrow made of short segments. `angle` rotates it (it spins while indexing).
static void DrawRefreshIcon(float cx, float cy, float r, double angle, const D2D1_COLOR_F& color) {
    const float s = (float)g_scale;
    const int kSegments = 16;
    const double span = 1.5 * kPi;  // 270 degrees
    SetBrush(color);
    D2D1_POINT_2F prev = D2D1::Point2F(cx + r * (float)std::cos(angle), cy + r * (float)std::sin(angle));
    for (int i = 1; i <= kSegments; ++i) {
        const double a = angle + span * i / kSegments;
        const D2D1_POINT_2F p = D2D1::Point2F(cx + r * (float)std::cos(a), cy + r * (float)std::sin(a));
        g_rt->DrawLine(prev, p, g_brush, 1.6f * s, g_roundStroke);
        prev = p;
    }
    // Arrowhead at the end of the arc: two short strokes swept back from the direction of travel.
    const double end = angle + span;
    const double bx = std::sin(end), by = -std::cos(end);  // opposite of the tangent
    for (int k = -1; k <= 1; k += 2) {
        const double w = 0.6 * k;
        const float dx = (float)(bx * std::cos(w) - by * std::sin(w));
        const float dy = (float)(bx * std::sin(w) + by * std::cos(w));
        g_rt->DrawLine(prev, D2D1::Point2F(prev.x + dx * 4.5f * s, prev.y + dy * 4.5f * s), g_brush,
                       1.6f * s, g_roundStroke);
    }
}

// Card footer: separator, reindex button on the left and shortcut hints on the right.
static bool CalcHistoryVisible();  // defined further down
static void DrawFooter(float cx, float footerTop, float cw, bool hasSel) {
    const float s = (float)g_scale;
    SetBrush(g_pal.separator);
    const float sepY = g_flip ? footerTop + kFooterH * s - 1.f : footerTop;
    D2D1_RECT_F sep = D2D1::RectF(cx + 12 * s, sepY, cx + cw - 12 * s, sepY + 1.f);
    g_rt->FillRectangle(&sep, g_brush);

    const float yMid = footerTop + kFooterH * s / 2 + 0.5f;

    const D2D1_RECT_F btn = ReindexButtonRect(cx, footerTop);
    if (g_hoverReindex) FillRR(btn.left, btn.top, btn.right, btn.bottom, 8 * s, g_pal.selection);
    const double angle = g_indexing ? std::fmod(NowSec() * 6.0, 2 * kPi) : 0.6;
    DrawRefreshIcon(btn.left + 18 * s, yMid, 6.5f * s, angle, g_hoverReindex ? g_pal.text : g_pal.textDim);
    DrawHint(kTxtReindex, kReindexKeys, 2, btn.right - 6 * s, yMid);

    // The calculation owns the footer while its history is on screen: it offers removing the
    // highlighted entry or clearing the whole history (same shortcut as "remove from recents").
    if (CalcHistoryVisible()) {
        const wchar_t* dk[3] = {L"Ctrl", L"Shift", L"R"};
        const float x = cx + cw - 20 * s;
        DrawHint(g_calcHistSel >= 0 ? kTxtCalcDelete : kTxtCalcClear, dk, 3, x, yMid);
        return;
    }
    if (!hasSel) return;

    const wchar_t* dk[2] = {L"Ctrl", L"I"};
    int nk = 2;
    switch (g_cfg.detailsKey) {
        case DetailsKey::CtrlI:     dk[1] = L"I"; break;
        case DetailsKey::CtrlK:     dk[1] = L"K"; break;
        case DetailsKey::CtrlSpace: dk[1] = L"Space"; break;
        case DetailsKey::F4:        dk[0] = L"F4"; nk = 1; break;
    }
    float x = cx + cw - 20 * s;
    x = DrawHint(kTxtDetails, dk, nk, x, yMid);

    x -= 12 * s;
    SetBrush(g_pal.separator);
    D2D1_RECT_F vdiv = D2D1::RectF(x, yMid - 9 * s, x + 1.f, yMid + 9 * s);
    g_rt->FillRectangle(&vdiv, g_brush);
    x -= 12 * s;

    const wchar_t* ok[1] = {kTxtEnterGlyph};
    DrawHint(kTxtOpen, ok, 1, x, yMid);
}

// True when a client point is over the (fully revealed) footer reindex button.
static bool HitReindex(int mx, int my) {
    if (g_vis == Vis::Hidden || !g_fmtHint || g_curH < ExpandedH() - 2) return false;
    const float s = (float)g_scale;
    float cx = 0, cy = 0;
    MainOrigin(cx, cy);
    const D2D1_RECT_F r = ReindexButtonRect(cx, GetLay(cy, (float)g_curH * s).footerTop);
    return mx >= r.left && mx < r.right && my >= r.top && my < r.bottom;
}

static void DrawDetailsPanel(AppEntry& app, const AppDetails& d) {
    const float s = (float)g_scale;
    const float a = (float)std::clamp(g_detailPos, 0.0, 1.0);
    float mainX = 0, mainY = 0;
    MainOrigin(mainX, mainY);
    // Attached to the right edge of the main panel; it slides in a bit when opening.
    const float ox = mainX + (kWidth + kPanelGap + (1.f - a) * 14.f) * s;
    const float oy = PanelOriginY(mainY);
    const float pw = kPanelW * s;
    const float ph = (float)DetailsPanelH() * s;   // always the same as the search bar
    const float pad = kPanelPad * s;

    // With live acrylic the DWM window behind the panel is only pw * a wide while it opens or
    // closes (see LiveSync), so it sweeps. The card's own layers (shadow, veil, glow, grain, rim,
    // border) and the content clip use that same width; at full width they would only fade and
    // would not follow the window.
    const float cardW = UseLive() ? std::max(1.f, pw * a) : pw;

    DrawCard(ox, oy, cardW, ph, a, CardFlags(true));

    D2D1_RECT_F clip = D2D1::RectF(ox, oy, ox + cardW, oy + ph);
    g_rt->PushAxisAlignedClip(&clip, D2D1_ANTIALIAS_MODE_ALIASED);

    const float icon = 44 * s;
    if (ID2D1Bitmap* bmp = EnsureIcon(app)) {
        D2D1_RECT_F dst = D2D1::RectF(ox + pad, oy + pad, ox + pad + icon, oy + pad + icon);
        g_rt->DrawBitmap(bmp, &dst, a, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
    } else {
        FillRR(ox + pad + 3 * s, oy + pad + 3 * s, ox + pad + icon - 3 * s, oy + pad + icon - 3 * s, 10 * s,
               g_pal.textDim, 0.18f * a);
    }
    const float tx = ox + pad + icon + 12 * s;
    DrawLabel(app.name, g_fmtPanelTitle, tx, oy + pad, ox + pw - pad, oy + pad + 24 * s, g_pal.text, a);
    DrawLabel(d.packaged ? L"Store application (MSIX)"
                         : (app.desktop ? L"Desktop shortcut" : L"Desktop application"),
              g_fmtPanelSub,
              tx, oy + pad + 24 * s, ox + pw - pad, oy + pad + 44 * s, g_pal.textDim, a);

    DrawLabel(kTxtActions, g_fmtSection, ox + pad, oy + 68 * s, ox + pw - pad, oy + 86 * s, g_pal.textDim, a);
    int acts[8];
    const int n = BuildActions(app, d, acts);
    const float actTop = oy + kPanelActionsTop * s;
    for (int k = 0; k < n; ++k) {
        const ActionDef* ad = FindAction(acts[k]);
        if (!ad) continue;
        const float y0 = actTop + k * kActionH * s;
        const float y1 = y0 + kActionH * s;
        if (acts[k] == g_hoverAction) {
            FillRR(ox + 8 * s, y0, ox + pw - 8 * s, y1, 8 * s, g_pal.selection, a);
        }
        DrawLabel(ad->label, g_fmtPanelRow, ox + pad, y0, ox + pw - pad, y1, g_pal.text, a);
        DrawLabel(ad->keys, g_fmtHint, ox + pad, y0, ox + pw - pad, y1, g_pal.textDim, a);
    }

    const float sepY = actTop + n * kActionH * s + 8 * s;
    SetBrush(g_pal.separator, a);
    D2D1_RECT_F sep = D2D1::RectF(ox + pad, sepY, ox + pw - pad, sepY + 1.f);
    g_rt->FillRectangle(&sep, g_brush);

    const float infoTop = sepY + 10 * s;
    DrawLabel(kTxtInfo, g_fmtSection, ox + pad, infoTop, ox + pw - pad, infoTop + 16 * s, g_pal.textDim, a);

    const float labelW = 84 * s;
    const float valX = ox + pad + labelW + 8 * s;
    const float valW = (ox + pw - pad) - valX;
    float ry = infoTop + 22 * s;
    for (const InfoRow& r : d.rows) {
        if (ry + kInfoRowH * s > oy + ph - 10 * s) break;
        DrawLabel(r.label, g_fmtPanelRow, ox + pad, ry, ox + pad + labelW, ry + kInfoRowH * s, g_pal.textDim, a);
        const std::wstring v = r.middle ? FitMiddle(r.value, g_fmtPanelRow, valW) : r.value;
        DrawLabel(v, g_fmtPanelRow, valX, ry, ox + pw - pad, ry + kInfoRowH * s, g_pal.text, a);
        ry += kInfoRowH * s;
    }

    g_rt->PopAxisAlignedClip();
}

// Id of the panel action under a client point, or -1
static int HitAction(int mx, int my) {
    if (!g_detailsOpen || g_detailPos < 0.6 || g_results.empty()) return -1;
    if (g_sel < 0 || g_sel >= (int)g_results.size()) return -1;
    const float s = (float)g_scale;
    float mainX = 0, mainY = 0;
    MainOrigin(mainX, mainY);
    const float lx = (mx - mainX) / s - (kWidth + kPanelGap);
    const float ly = (my - PanelOriginY(mainY)) / s;
    if (lx < 8 || lx > kPanelW - 8) return -1;
    AppEntry& a = g_apps[g_results[g_sel].app];
    const AppDetails& d = GetDetails(a);
    int acts[8];
    const int n = BuildActions(a, d, acts);
    for (int k = 0; k < n; ++k) {
        const float y0 = kPanelActionsTop + k * kActionH;
        if (ly >= y0 && ly < y0 + kActionH) return acts[k];
    }
    return -1;
}

// Canonical form used ONLY inside the cards (never in the search field, which always shows exactly
// what the user typed): typographic maths symbols instead of the raw ones, and no spaces, so every
// entry reads the same no matter how it was written or pasted.
static bool IsCalcSymbol(wchar_t c);  // defined below

// Renders an expression for the cards: operator glyphs become math symbols, spaces around
// operators are dropped, but spaces between words (e.g. "10 km to miles") are kept.
static std::wstring CalcDisplayExpr(const std::wstring& in) {
    auto isSpace = [](wchar_t c) {
        return c == L' ' || c == L'\t' || c == L'\r' || c == L'\n' || c == 0x00A0 || c == 0x2009;
    };
    auto isWord = [](wchar_t c) {
        if (IsCalcSymbol(c)) return false;
        return (c >= L'0' && c <= L'9') || (c >= L'a' && c <= L'z') ||
               (c >= L'A' && c <= L'Z') || c >= 0x80;
    };
    std::wstring out;
    out.reserve(in.size());
    for (size_t idx = 0; idx < in.size(); ++idx) {
        const wchar_t c = Calc::detail::NormalizeMathChar(in[idx]);
        if (isSpace(c)) {
            const wchar_t prev = out.empty() ? 0 : out.back();
            wchar_t next = 0;
            for (size_t k = idx + 1; k < in.size(); ++k) {
                const wchar_t nc = Calc::detail::NormalizeMathChar(in[k]);
                if (!isSpace(nc)) { next = nc; break; }
            }
            if (isWord(prev) && isWord(next) && (out.empty() || out.back() != L' ')) {
                out.push_back(L' ');
            }
            continue;
        }
        switch (c) {
            case L'*': out.push_back(L'\u00D7'); break;  // ×
            case L'/': out.push_back(L'\u00F7'); break;  // ÷
            case L'-': out.push_back(L'\u2212'); break;  // −
            default: out.push_back(c);
        }
    }
    return out;
}

// The operator glyphs drawn in their own (lighter) colour inside the cards.
static bool IsCalcSymbol(wchar_t c) {
    return c == L'\u00D7' || c == L'\u00F7' || c == L'\u2212' || c == L'+' || c == L'^' ||
           c == L'%' || c == L'!';
}

// Draws an expression with the operator glyphs in a lighter colour. Runs are measured and placed
// manually so the two colours butt together; drawing is clipped to `maxX`.
static void DrawCalcExpr(const std::wstring& expr, IDWriteTextFormat* fmt, const D2D1_COLOR_F& c,
                         float alpha, float symAlpha, float x, float y0, float y1, float maxX) {
    if (!fmt || expr.empty()) return;
    size_t i = 0;
    while (i < expr.size() && x < maxX) {
        const bool sym = IsCalcSymbol(expr[i]);
        size_t j = i;
        while (j < expr.size() && IsCalcSymbol(expr[j]) == sym) ++j;
        const std::wstring run = expr.substr(i, j - i);
        const float w = TextWidth(run.c_str(), fmt);
        DrawLabel(run, fmt, x, y0, std::min(x + w + 2, maxX), y1, c, sym ? symAlpha : alpha);
        x += w;
        i = j;
    }
}

// Calculator result card, drawn in the space reserved above the list. It shows the typed
// expression, the result (or a short error) and, on the right, how to copy it. After a copy it
// briefly flashes "Copied".
static void DrawCalcHero(float cx, float top, float cw) {
    const float s = (float)g_scale;
    const float pad = 14.f * s;
    const float x0 = cx + 8 * s;
    const float x1 = cx + cw - 8 * s;
    const float y0 = top + kListPad * s;
    const float y1 = y0 + (kHeroH - 2 * kListPad) * s;

    FillRR(x0, y0, x1, y1, kRowRadius * s, g_pal.selection);
    SetBrush(g_pal.border);
    D2D1_ROUNDED_RECT b = D2D1::RoundedRect(
        D2D1::RectF(x0 + 0.5f, y0 + 0.5f, x1 - 0.5f, y1 - 0.5f), kRowRadius * s, kRowRadius * s);
    g_rt->DrawRoundedRectangle(&b, g_brush, 1.f);

    const float midY = (y0 + y1) / 2;
    const float textW = (x1 - 150 * s) - (x0 + pad);

    D2D1_RECT_F clip = D2D1::RectF(x0, y0, x1 - 132 * s, y1);
    g_rt->PushAxisAlignedClip(&clip, D2D1_ANTIALIAS_MODE_ALIASED);

    // Small expression on top, in the canonical card format with lighter operator glyphs.
    DrawCalcExpr(CalcDisplayExpr(g_text), g_fmtTitle, g_pal.textDim, 0.9f, 0.5f, x0 + pad,
                 y0 + 6 * s, midY + 2 * s, x0 + pad + textW);

    if (CalcOk()) {
        std::wstring res = L"= " + g_calcDisplay;
        SetBrush(g_pal.text);
        D2D1_RECT_F rr = D2D1::RectF(x0 + pad, midY - 2 * s, x0 + pad + textW, y1 - 4 * s);
        g_rt->DrawText(res.c_str(), (UINT32)res.size(), g_fmtInput, &rr, g_brush);
    } else {
        SetBrush(g_pal.textDim);
        D2D1_RECT_F rr = D2D1::RectF(x0 + pad, midY - 2 * s, x0 + pad + textW, y1 - 4 * s);
        g_rt->DrawText(g_calc.error.c_str(), (UINT32)g_calc.error.size(), g_fmtTitle, &rr, g_brush);
    }
    g_rt->PopAxisAlignedClip();

    // The action hint belongs to whatever is selected: the result card only shows it while the
    // selection is on the result itself (not while a history row is selected).
    if (CalcOk() && g_calcHistSel < 0) {
        const bool copied = (NowSec() - g_copiedAt) < 1.4;
        if (copied) {
            SetBrush(g_pal.accent);
            D2D1_RECT_F cr = D2D1::RectF(x1 - 120 * s, y0, x1 - pad, y1);
            g_rt->DrawText(kTxtCalcCopied, (UINT32)wcslen(kTxtCalcCopied), g_fmtHint, &cr, g_brush);
        } else {
            const wchar_t* const keys[1] = {kTxtEnterGlyph};
            DrawHint(kTxtCalcCopy, keys, 1, x1 - pad, midY);
        }
    }
}

// Compact, muted rows below the result card with recent calculations. They are deliberately
// plainer than the result card (no border, dimmer text) so the two are not confused. Clicking a
// row (or picking it with the arrows and Enter) inserts its result at the caret.
static void ReplaceSelection(const std::wstring& s);  // defined further down

static void DrawCalcHistory(float cx, float listTop, float cw, float histBottom) {
    if (g_calcHist.empty()) return;
    const float s = (float)g_scale;
    const float origin = listTop + (kListPad + (float)HeroH()) * s;
    const float listBottom = histBottom;

    const float rowX0 = cx + 8 * s;
    const float rowX1 = cx + cw - 8 * s;
    const float headerH = kSectionH * s;
    const float rowH = kHistRowH * s;
    const float firstY = origin + headerH - (float)g_histScroll * s;

    // Clip the whole history to the area below the result card, so rows (and the header) slide
    // under it while scrolling instead of drawing over it.
    D2D1_RECT_F hclip = D2D1::RectF(cx, origin, cx + cw, listBottom);
    g_rt->PushAxisAlignedClip(&hclip, D2D1_ANTIALIAS_MODE_ALIASED);

    // Section label, scrolls with the rows (like the "Recent" / "Suggestions" headers).
    SetBrush(g_pal.textDim);
    const float headerY = origin - (float)g_histScroll * s;
    D2D1_RECT_F hr = D2D1::RectF(rowX0 + 10 * s, headerY, rowX1, headerY + headerH);
    g_rt->DrawText(kTxtCalcHistory, (UINT32)wcslen(kTxtCalcHistory), g_fmtSection, &hr, g_brush);

    const int n = (int)g_calcHist.size();
    for (int i = 0; i < n; ++i) {
        const float y = firstY + (float)i * rowH;
        if (y + rowH <= origin || y >= listBottom) continue;

        const bool sel = (i == g_calcHistSel);
        if (sel) {
            FillRR(rowX0, y + 1, rowX1, y + rowH - 1, 8 * s, g_pal.text, 0.07f);
        }

        // The selected row shows its own action hints ("Edit [Tab]" and "Add to operation [Enter]");
        // the others leave that space to the result text.
        const wchar_t* const addKeys[1] = {kTxtEnterGlyph};
        const wchar_t* const editKeys[1] = {L"Tab"};
        const float hintW = sel ? HintWidth(kTxtCalcAdd, addKeys, 1) + 14 * s +
                                      HintWidth(kTxtCalcEdit, editKeys, 1) + 10 * s
                                : 0.f;
        const float resRight = rowX1 - 14 * s - hintW;

        // The result takes the width it needs (up to ~62% of the row) so longer values such as
        // "1,000 MB  (binary 1,024 MB)" stay readable; the expression gets what is left.
        const std::wstring res = L"= " + g_calcHist[i].resFmt;
        const float maxResW = (rowX1 - rowX0) * 0.62f;
        const float resW = std::min(TextWidth(res.c_str(), g_fmtHint) + 6 * s, maxResW);
        const float resLeft = resRight - resW;

        const float tx = rowX0 + 16 * s;
        const float tw = std::max(0.f, (resLeft - 10 * s) - tx);
        DrawCalcExpr(CalcDisplayExpr(g_calcHist[i].expr), g_fmtTitle, g_pal.text, 0.6f, 0.33f, tx, y,
                     y + rowH, tx + tw);

        SetBrush(g_pal.text, 0.5f);
        D2D1_RECT_F rr = D2D1::RectF(resLeft, y, resRight, y + rowH);
        g_rt->DrawText(res.c_str(), (UINT32)res.size(), g_fmtHint, &rr, g_brush);

        if (sel) {
            float hx = DrawHint(kTxtCalcAdd, addKeys, 1, rowX1 - 8 * s, y + rowH / 2);
            DrawHint(kTxtCalcEdit, editKeys, 1, hx - 14 * s, y + rowH / 2);
        }
    }
    g_rt->PopAxisAlignedClip();
}

// Height (DIP) available for the history rows (shared with the app list viewport).
static double CalcHistViewportH() {
    return ListViewportH();
}

static double CalcHistContentH() {
    return kSectionH + (double)g_calcHist.size() * kHistRowH;
}

static void ClampHistScroll() {
    const double maxScroll = std::max(0.0, CalcHistContentH() - CalcHistViewportH());
    g_histScroll = std::clamp(g_histScroll, 0.0, maxScroll);
}

static void EnsureHistSelVisible() {
    if (g_calcHistSel < 0) return;
    const double top = kSectionH + g_calcHistSel * (double)kHistRowH;
    const double bot = top + kHistRowH;
    const double view = CalcHistViewportH();
    if (top < g_histScroll) {
        g_histScroll = top;
    } else if (bot > g_histScroll + view) {
        g_histScroll = bot - view;
    }
    ClampHistScroll();
}

// Index of the history row under a client point, or -1.
static int HitCalcHistory(int mx, int my) {
    if (!g_calcActive || g_calcHist.empty()) return -1;
    const float s = (float)g_scale;
    float cx = 0, cy = 0;
    MainOrigin(cx, cy);
    const float cw = kWidth * s;
    if (mx < cx || mx > cx + cw) return -1;
    const Lay L = GetLay(cy, (float)g_curH * s);
    const float origin = L.listTop + (kListPad + (float)HeroH()) * s;
    const float listBottom = L.histBottom;
    if (my < origin || my >= listBottom) return -1;
    const float firstY = origin + kSectionH * s - (float)g_histScroll * s;
    const int idx = (int)std::floor((my - firstY) / (kHistRowH * s));
    if (idx < 0 || idx >= (int)g_calcHist.size()) return -1;
    return idx;
}

static void InsertCalcHistory(int i) {
    if (i < 0 || i >= (int)g_calcHist.size()) return;
    const std::wstring& v = g_calcHist[i].insVal.empty() ? g_calcHist[i].resFmt
                                                         : g_calcHist[i].insVal;
    ReplaceSelection(v);
}

// Moves a history entry's original expression into the search field (replacing whatever is there)
// so it can be edited. Bound to Tab while a history row is selected.
static void EditCalcHistoryOp(int i) {
    if (i < 0 || i >= (int)g_calcHist.size()) return;
    const std::wstring e = g_calcHist[i].expr;
    if (e.empty() || e.size() > 200) return;
    g_text = e;
    g_caret = g_anchor = (int)g_text.size();
    OnTextChanged();
}

// The history is drawn (and interactive) whenever the text is a recognised maths expression and
// no app results are shown: it stays visible while the user is still composing an expression
// (a partial/errored one), so a previous result can be dropped into the current operation.
static bool CalcHistoryVisible() {
    return g_calcActive && g_results.empty() && !g_calcHist.empty();
}

// Removes one history entry (its position in the list is its index).
static void DeleteCalcHistory(int i) {
    if (i < 0 || i >= (int)g_calcHist.size()) return;
    g_calcHist.erase(g_calcHist.begin() + i);
    if (g_calcHistSel > i) {
        --g_calcHistSel;
    } else if (g_calcHistSel == i) {
        g_calcHistSel = (i < (int)g_calcHist.size()) ? i : (int)g_calcHist.size() - 1;
    }
    if (g_calcHist.empty()) {
        g_calcHistSel = -1;
        g_histScroll = 0;
    } else {
        ClampHistScroll();
        EnsureHistSelVisible();
    }
    SaveCalcHistory();
    UpdateTargets(false, /*followSelection=*/false);
    MarkDirty();
}

static void ClearCalcHistory() {
    if (g_calcHist.empty()) return;
    g_calcHist.clear();
    g_calcHistSel = -1;
    g_histScroll = 0;
    SaveCalcHistory();
    UpdateTargets(false, /*followSelection=*/false);
    MarkDirty();
}

// Tile + vector glyph for the power commands (no font or image dependency).
static void DrawCmdTile(int cmd, float x, float y, float size) {
    const float s = (float)g_scale;
    const float cx = x + size / 2, cy = y + size / 2;
    FillRR(x + 2 * s, y + 2 * s, x + size - 2 * s, y + size - 2 * s, 9 * s, g_pal.accent, 0.20f);
    const float r = size * 0.26f;
    const float sw = 2.f * s;
    auto arc = [&](float ccx, float ccy, float rad, double a0, double a1) {
        const int kSeg = 24;
        D2D1_POINT_2F prev = D2D1::Point2F(ccx + rad * (float)std::cos(a0), ccy + rad * (float)std::sin(a0));
        for (int i = 1; i <= kSeg; ++i) {
            const double a = a0 + (a1 - a0) * i / kSeg;
            const D2D1_POINT_2F p = D2D1::Point2F(ccx + rad * (float)std::cos(a), ccy + rad * (float)std::sin(a));
            g_rt->DrawLine(prev, p, g_brush, sw, g_roundStroke);
            prev = p;
        }
    };
    auto line = [&](float x0, float y0, float x1, float y1) {
        g_rt->DrawLine(D2D1::Point2F(x0, y0), D2D1::Point2F(x1, y1), g_brush, sw, g_roundStroke);
    };
    SetBrush(g_pal.accent);
    switch (cmd) {
        case CMD_SHUTDOWN:
            arc(cx, cy + r * 0.1f, r, (-90.0 + 40.0) * kPi / 180.0, (-90.0 + 320.0) * kPi / 180.0);
            line(cx, cy - r * 1.0f, cx, cy - r * 0.05f);
            break;
        case CMD_RESTART:
            DrawRefreshIcon(cx, cy, r, 0.6, g_pal.accent);
            break;
        case CMD_HIBERNATE:
        case CMD_SLEEP: {
            ID2D1EllipseGeometry* a = nullptr;
            ID2D1EllipseGeometry* b = nullptr;
            ID2D1PathGeometry* path = nullptr;
            ID2D1GeometrySink* sink = nullptr;
            g_d2d->CreateEllipseGeometry(D2D1::Ellipse(D2D1::Point2F(cx, cy), r, r), &a);
            g_d2d->CreateEllipseGeometry(
                D2D1::Ellipse(D2D1::Point2F(cx + r * 0.55f, cy - r * 0.35f), r * 0.85f, r * 0.85f), &b);
            if (a && b && SUCCEEDED(g_d2d->CreatePathGeometry(&path)) && path && SUCCEEDED(path->Open(&sink)) &&
                sink) {
                a->CombineWithGeometry(b, D2D1_COMBINE_MODE_EXCLUDE, nullptr, sink);
                sink->Close();
                g_rt->FillGeometry(path, g_brush);
            }
            SafeRelease(sink);
            SafeRelease(path);
            SafeRelease(b);
            SafeRelease(a);
            break;
        }
        case CMD_LOGOUT:
            line(cx - r * 0.1f, cy - r * 0.85f, cx - r * 0.85f, cy - r * 0.85f);
            line(cx - r * 0.85f, cy - r * 0.85f, cx - r * 0.85f, cy + r * 0.85f);
            line(cx - r * 0.85f, cy + r * 0.85f, cx - r * 0.1f, cy + r * 0.85f);
            line(cx - r * 0.35f, cy, cx + r * 0.9f, cy);
            line(cx + r * 0.9f, cy, cx + r * 0.5f, cy - r * 0.4f);
            line(cx + r * 0.9f, cy, cx + r * 0.5f, cy + r * 0.4f);
            break;
        case CMD_LOCK:
            FillRR(cx - r * 0.9f, cy - r * 0.05f, cx + r * 0.9f, cy + r * 0.95f, 2.5f * s, g_pal.accent);
            SetBrush(g_pal.accent);
            arc(cx, cy - r * 0.05f, r * 0.55f, kPi, 2.0 * kPi);
            break;
        case CMD_MUTE:
        case CMD_VOLUP:
        case CMD_VOLDOWN: {
            const float x0 = cx - r * 0.9f, x1 = cx - r * 0.4f, x2 = cx + r * 0.1f;
            line(x0, cy - r * 0.35f, x1, cy - r * 0.35f);
            line(x1, cy - r * 0.35f, x2, cy - r * 0.8f);
            line(x2, cy - r * 0.8f, x2, cy + r * 0.8f);
            line(x2, cy + r * 0.8f, x1, cy + r * 0.35f);
            line(x1, cy + r * 0.35f, x0, cy + r * 0.35f);
            line(x0, cy + r * 0.35f, x0, cy - r * 0.35f);
            if (cmd == CMD_MUTE) {
                line(cx + r * 0.45f, cy - r * 0.4f, cx + r * 1.05f, cy + r * 0.4f);
                line(cx + r * 0.45f, cy + r * 0.4f, cx + r * 1.05f, cy - r * 0.4f);
            } else {
                arc(x2, cy, r * 0.55f, -0.75, 0.75);
                if (cmd == CMD_VOLUP) arc(x2, cy, r * 0.95f, -0.75, 0.75);
            }
            break;
        }
        case CMD_PLAYPAUSE:
            line(cx - r * 0.9f, cy - r * 0.8f, cx - r * 0.9f, cy + r * 0.8f);
            line(cx - r * 0.9f, cy - r * 0.8f, cx - r * 0.05f, cy);
            line(cx - r * 0.05f, cy, cx - r * 0.9f, cy + r * 0.8f);
            line(cx + r * 0.45f, cy - r * 0.8f, cx + r * 0.45f, cy + r * 0.8f);
            line(cx + r * 0.95f, cy - r * 0.8f, cx + r * 0.95f, cy + r * 0.8f);
            break;
        case CMD_NEXT:
            line(cx - r * 0.8f, cy - r * 0.8f, cx - r * 0.8f, cy + r * 0.8f);
            line(cx - r * 0.8f, cy - r * 0.8f, cx + r * 0.4f, cy);
            line(cx + r * 0.4f, cy, cx - r * 0.8f, cy + r * 0.8f);
            line(cx + r * 0.85f, cy - r * 0.8f, cx + r * 0.85f, cy + r * 0.8f);
            break;
        case CMD_PREV:
            line(cx + r * 0.8f, cy - r * 0.8f, cx + r * 0.8f, cy + r * 0.8f);
            line(cx + r * 0.8f, cy - r * 0.8f, cx - r * 0.4f, cy);
            line(cx - r * 0.4f, cy, cx + r * 0.8f, cy + r * 0.8f);
            line(cx - r * 0.85f, cy - r * 0.8f, cx - r * 0.85f, cy + r * 0.8f);
            break;
        case CMD_DARKMODE: {
            arc(cx, cy, r, 0.0, 2.0 * kPi);
            ID2D1PathGeometry* path = nullptr;
            ID2D1GeometrySink* sink = nullptr;
            if (SUCCEEDED(g_d2d->CreatePathGeometry(&path)) && path && SUCCEEDED(path->Open(&sink)) && sink) {
                sink->BeginFigure(D2D1::Point2F(cx, cy - r), D2D1_FIGURE_BEGIN_FILLED);
                sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(cx, cy + r), D2D1::SizeF(r, r), 0.f,
                                              D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
                sink->EndFigure(D2D1_FIGURE_END_CLOSED);
                sink->Close();
                g_rt->FillGeometry(path, g_brush);
            }
            SafeRelease(sink);
            SafeRelease(path);
            break;
        }
        case CMD_DISPLAYOFF:
            line(cx - r, cy - r * 0.7f, cx + r, cy - r * 0.7f);
            line(cx + r, cy - r * 0.7f, cx + r, cy + r * 0.5f);
            line(cx + r, cy + r * 0.5f, cx - r, cy + r * 0.5f);
            line(cx - r, cy + r * 0.5f, cx - r, cy - r * 0.7f);
            line(cx, cy + r * 0.5f, cx, cy + r * 0.9f);
            line(cx - r * 0.5f, cy + r * 0.9f, cx + r * 0.5f, cy + r * 0.9f);
            break;
        case CMD_SHOWDESKTOP:
            line(cx - r, cy - r * 0.7f, cx + r, cy - r * 0.7f);
            line(cx + r, cy - r * 0.7f, cx + r, cy + r * 0.7f);
            line(cx + r, cy + r * 0.7f, cx - r, cy + r * 0.7f);
            line(cx - r, cy + r * 0.7f, cx - r, cy - r * 0.7f);
            line(cx - r, cy - r * 0.25f, cx + r, cy - r * 0.25f);
            break;
        case CMD_RECYCLE:
            line(cx - r * 0.85f, cy - r * 0.55f, cx + r * 0.85f, cy - r * 0.55f);
            line(cx - r * 0.3f, cy - r * 0.55f, cx - r * 0.3f, cy - r * 0.85f);
            line(cx - r * 0.3f, cy - r * 0.85f, cx + r * 0.3f, cy - r * 0.85f);
            line(cx + r * 0.3f, cy - r * 0.85f, cx + r * 0.3f, cy - r * 0.55f);
            line(cx - r * 0.6f, cy - r * 0.55f, cx - r * 0.45f, cy + r * 0.9f);
            line(cx - r * 0.45f, cy + r * 0.9f, cx + r * 0.45f, cy + r * 0.9f);
            line(cx + r * 0.45f, cy + r * 0.9f, cx + r * 0.6f, cy - r * 0.55f);
            break;
    }
}

static void Render() {
    if (!g_dib || !g_dw || !EnsureTarget()) {
        return;
    }
    const float s = (float)g_scale;

    // Details panel data (computed before drawing starts). If there is no longer a
    // selection (e.g. the text was deleted) the panel keeps showing the last app while it
    // fades out.
    AppEntry* panelApp = nullptr;
    const AppDetails* panelDetails = nullptr;
    if (g_detailPos > 0.01) {
        if (g_sel >= 0 && g_sel < (int)g_results.size()) {
            panelApp = &g_apps[g_results[g_sel].app];
        } else if (!g_panelAppId.empty()) {
            for (auto& a : g_apps) {
                if (a.id == g_panelAppId) {
                    panelApp = &a;
                    break;
                }
            }
        }
        if (panelApp) panelDetails = &GetDetails(*panelApp);
    }

    RECT rc = {0, 0, g_bmpW, g_bmpH};
    HRESULT hrBind = g_rt->BindDC(g_memDC, &rc);
    if (FAILED(hrBind)) {
        return;
    }
    g_rt->BeginDraw();
    g_rt->SetTransform(D2D1::Matrix3x2F::Identity());
    g_rt->Clear(D2D1::ColorF(0, 0, 0, 0));
    g_rt->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
    g_rt->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE);
    bool pushedInnerClip = false;
    if (g_clipInner) {
        const float wx = (float)(g_winX + g_offX), wy = (float)(g_winY + g_offY);
        D2D1_RECT_F cr = D2D1::RectF((float)g_clipRect.left - wx, (float)g_clipRect.top - wy,
                                     (float)g_clipRect.right - wx, (float)g_clipRect.bottom - wy);
        g_rt->PushAxisAlignedClip(&cr, D2D1_ANTIALIAS_MODE_ALIASED);
        pushedInnerClip = true;
    }

    float cx = 0, cy = 0;
    MainOrigin(cx, cy);
    const float cw = kWidth * s;
    const float ch = (float)g_curH * s;

    // "Pop up" animation: scale the whole card around its center.
    if (std::fabs(g_animScale - 1.0) > 1e-4) {
        const float sc = (float)g_animScale;
        g_rt->SetTransform(D2D1::Matrix3x2F::Scale(sc, sc, D2D1::Point2F(cx + cw / 2, cy + ch / 2)));
    }

    DrawCard(cx, cy, cw, ch, 1.f, CardFlags(false));

    const Lay lay = GetLay(cy, ch);
    const float by = lay.barTop;  // top of the search bar

    // ---- Search bar ----
    const float barMid = by + kBarH * s / 2;
    DrawMagnifier(cx + 30 * s, barMid);

    const float fieldX = cx + 58 * s;
    const float fieldW = (kWidth - 58 - 24) * s;
    {
        D2D1_RECT_F clip = D2D1::RectF(fieldX, by, fieldX + fieldW, by + kBarH * s);
        g_rt->PushAxisAlignedClip(&clip, D2D1_ANTIALIAS_MODE_ALIASED);

        if (g_text.empty()) {
            SetBrush(g_pal.textDim, 0.85f);
            D2D1_RECT_F r = D2D1::RectF(fieldX, by, fieldX + fieldW, by + kBarH * s);
            const std::wstring ph = g_cfg.placeholder.empty() ? std::wstring(kTxtPlaceholder) : g_cfg.placeholder;
            g_rt->DrawText(ph.c_str(), (UINT32)ph.size(), g_fmtInput, &r, g_brush);
            if (g_caretOn && g_vis != Vis::Hiding) {
                SetBrush(g_pal.text);
                float ch2 = 26 * s;
                D2D1_RECT_F cr = D2D1::RectF(fieldX, barMid - ch2 / 2, fieldX + 1.5f * s, barMid + ch2 / 2);
                g_rt->FillRectangle(&cr, g_brush);
            }
        } else {
            IDWriteTextLayout* tl = nullptr;
            g_dw->CreateTextLayout(g_text.c_str(), (UINT32)g_text.size(), g_fmtInput, 10000.f,
                                   kBarH * s, &tl);
            if (tl) {
                float cxPos = 0, cyTmp = 0;
                DWRITE_HIT_TEST_METRICS hm = {};
                tl->HitTestTextPosition((UINT32)g_caret, FALSE, &cxPos, &cyTmp, &hm);

                if (cxPos - g_inputScroll > fieldW - 4 * s) g_inputScroll = cxPos - (fieldW - 4 * s);
                if (cxPos - g_inputScroll < 0) g_inputScroll = cxPos;
                if (g_inputScroll < 0) g_inputScroll = 0;

                const float ox = fieldX - g_inputScroll;
                float chh = 26 * s;

                if (g_anchor != g_caret) {
                    float ax = 0, ay = 0;
                    DWRITE_HIT_TEST_METRICS hm2 = {};
                    tl->HitTestTextPosition((UINT32)g_anchor, FALSE, &ax, &ay, &hm2);
                    float x0 = std::min(ax, cxPos);
                    float x1 = std::max(ax, cxPos);
                    SetBrush(g_pal.caretSel);
                    D2D1_RECT_F sr = D2D1::RectF(ox + x0, barMid - chh / 2, ox + x1, barMid + chh / 2);
                    g_rt->FillRectangle(&sr, g_brush);
                }

                SetBrush(g_pal.text);
                g_rt->DrawTextLayout(D2D1::Point2F(ox, by), tl, g_brush);

                // Inline calculator result, faintly after the typed text.
                if (GhostShown()) {
                    float endX = 0, endY = 0;
                    DWRITE_HIT_TEST_METRICS hmEnd = {};
                    tl->HitTestTextPosition((UINT32)g_text.size(), FALSE, &endX, &endY, &hmEnd);
                    std::wstring ghost = L"   = " + g_calcDisplay;
                    SetBrush(g_pal.textDim, 0.75f);
                    D2D1_RECT_F gr = D2D1::RectF(ox + endX, by, fieldX + fieldW, by + kBarH * s);
                    g_rt->DrawText(ghost.c_str(), (UINT32)ghost.size(), g_fmtInput, &gr, g_brush);
                }

                if (g_caretOn && g_vis != Vis::Hiding) {
                    SetBrush(g_pal.text);
                    D2D1_RECT_F cr =
                        D2D1::RectF(ox + cxPos, barMid - chh / 2, ox + cxPos + 1.5f * s, barMid + chh / 2);
                    g_rt->FillRectangle(&cr, g_brush);
                }
                tl->Release();
            }
        }
        g_rt->PopAxisAlignedClip();
    }

    // ---- List / messages ----
    const float listTop = lay.listTop;
    const int rows = VisibleRows();

    if (ch > kBarH * s + 2) {
        SetBrush(g_pal.separator);
        const float sepY = g_flip ? lay.barTop : listTop;
        D2D1_RECT_F sep = D2D1::RectF(cx + 12 * s, sepY, cx + cw - 12 * s, sepY + 1.f);
        g_rt->FillRectangle(&sep, g_brush);
    }

    // Calculator result card, in the space reserved above the list.
    if (ch > kBarH * s + 2 && HeroShown()) {
        D2D1_RECT_F cardClip = D2D1::RectF(cx, cy, cx + cw, cy + ch);
        g_rt->PushAxisAlignedClip(&cardClip, D2D1_ANTIALIAS_MODE_ALIASED);
        DrawCalcHero(cx, listTop, cw);
        g_rt->PopAxisAlignedClip();
    }

    // The footer takes the end of the expanded height; the list ends just above it.
    const float footerTop = lay.footerTop;
    const float listBottom = lay.listBottom;
    D2D1_RECT_F listClip = D2D1::RectF(cx, std::max(listTop + 1.f, cy), cx + cw, listBottom);
    g_rt->PushAxisAlignedClip(&listClip, D2D1_ANTIALIAS_MODE_ALIASED);

    if (rows > 0) {
        const float rowsOrigin = RowsOriginPx(lay);
        const float rowH = kRowH * s;
        const float rowX0 = cx + 8 * s;
        const float rowX1 = cx + cw - 8 * s;
        const double scrollOff = ScrollPx();

        const float hlY = rowsOrigin + (float)(RowOffset(g_selPos) - scrollOff) * s;
        FillRR(rowX0, hlY, rowX1, hlY + rowH, kRowRadius * s, g_pal.selection);
        {
            SetBrush(g_pal.text, 0.06f);
            D2D1_ROUNDED_RECT so = D2D1::RoundedRect(
                D2D1::RectF(rowX0 + 0.5f, hlY + 0.5f, rowX1 - 0.5f, hlY + rowH - 0.5f), kRowRadius * s,
                kRowRadius * s);
            g_rt->DrawRoundedRectangle(&so, g_brush, 1.f);
        }

        const float iconPx = kIconSize * s;
        const float textX = rowX0 + (10 + kIconSize + 14) * s;
        const float textW = (rowX1 - textX) - 130 * s;

        int first = std::max(0, (int)std::floor(g_scrollPos) - (g_kbScroll ? 2 : 0));
        int last = std::min((int)g_results.size() - 1, (int)std::ceil(g_scrollPos) + rows);
        for (int i = first; i <= last; ++i) {
            SearchResult& res = g_results[i];
            AppEntry& app = g_apps[res.app];
            float y = rowsOrigin + (float)(RowOffset((double)i) - scrollOff) * s;

            // Section header ("Recent" / "Suggestions") above the first row of each group
            if (res.section != 0 && (i == 0 || g_results[i - 1].section != res.section)) {
                const wchar_t* secTxt = (res.section == 1) ? kTxtRecents : kTxtSuggestions;
                SetBrush(g_pal.textDim);
                D2D1_RECT_F secRect = D2D1::RectF(rowX0 + 10 * s, y - kSectionH * s, rowX1, y);
                g_rt->DrawText(secTxt, (UINT32)wcslen(secTxt), g_fmtSection, &secRect, g_brush);
            }

            float ix = rowX0 + 10 * s;
            float iy = y + (rowH - iconPx) / 2;
            ID2D1Bitmap* bmp = app.isCmd ? nullptr : EnsureIcon(app);
            if (app.isCmd) {
                DrawCmdTile(app.cmdId, ix, iy, iconPx);
            } else if (bmp) {
                D2D1_RECT_F dst = D2D1::RectF(ix, iy, ix + iconPx, iy + iconPx);
                g_rt->DrawBitmap(bmp, &dst, 1.f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
            } else {
                FillRR(ix + 2 * s, iy + 2 * s, ix + iconPx - 2 * s, iy + iconPx - 2 * s, 8 * s,
                       g_pal.textDim, 0.18f);
            }

            if (!res.layout) {
                res.layout = BuildTitleLayout(app, textW, rowH);
            }
            if (res.layout) {
                SetBrush(g_pal.text);
                g_rt->DrawTextLayout(D2D1::Point2F(textX, y), res.layout, g_brush);
            }

            // Type label, on the right (like "Application" / "Command" in other launchers)
            {
                const bool armed = app.isCmd && g_cmdArmed == res.app && (NowSec() - g_cmdArmedAt) < 4.0;
                const wchar_t* typeTxt =
                    app.isWin ? app.sub.c_str()
                    : app.isCmd ? (armed ? kTxtConfirm : kTxtTypeCommand)
                              : (app.desktop ? kTxtTypeDesktop
                                             : (IsPackagedId(app.id) ? kTxtTypeStore : kTxtTypeApp));
                SetBrush(armed ? g_pal.accent : g_pal.textDim);
                D2D1_RECT_F tr = D2D1::RectF(rowX1 - 150 * s, y, rowX1 - 14 * s, y + rowH);
                g_rt->DrawText(typeTxt, (UINT32)wcslen(typeTxt), g_fmtHint, &tr, g_brush);
            }
        }
    } else if (g_calcActive) {
        DrawCalcHistory(cx, listTop, cw, lay.histBottom);
    } else if (ch > kBarH * s + 8) {
        const wchar_t* msg = nullptr;
        if (!g_tokens.empty() && !CalcShown()) {
            msg = kTxtNoResults;
        } else if (g_apps.empty() && !g_indexedOnce && !CalcShown()) {
            msg = kTxtIndexing;
        }
        if (msg) {
            SetBrush(g_pal.textDim);
            // "No results" is centered in the whole list area; "Indexing…" is a short row
            float msgTop = listTop + 1.f;
            float msgBottom = g_tokens.empty() ? listTop + kEmptyRowH * s : listBottom;
            if (g_flip && g_tokens.empty()) {
                msgBottom = lay.barTop - kListPad * s;
                msgTop = lay.barTop - kEmptyRowH * s;
            }
            D2D1_RECT_F r = D2D1::RectF(cx, msgTop, cx + cw, msgBottom);
            g_rt->DrawText(msg, (UINT32)wcslen(msg), g_fmtEmpty, &r, g_brush);
        }
    }
    g_rt->PopAxisAlignedClip();

    // ---- Footer with shortcuts (revealed as the card expands) ----
    const bool footVisible = g_flip ? (footerTop + kFooterH * s > cy + 2.f) : (cy + ch > footerTop + 2.f);
    if (footVisible) {
        D2D1_RECT_F footClip = g_flip ? D2D1::RectF(cx, std::max(footerTop, cy), cx + cw, footerTop + kFooterH * s)
                                      : D2D1::RectF(cx, footerTop, cx + cw, cy + ch);
        g_rt->PushAxisAlignedClip(&footClip, D2D1_ANTIALIAS_MODE_ALIASED);
        DrawFooter(cx, footerTop, cw, !g_results.empty() && g_sel >= 0 && g_sel < (int)g_results.size());
        g_rt->PopAxisAlignedClip();
    }

    // ---- Details panel (on the right) ----
    if (panelApp && panelDetails) {
        DrawDetailsPanel(*panelApp, *panelDetails);
    }

    if (pushedInnerClip) g_rt->PopAxisAlignedClip();
    HRESULT hr = g_rt->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET) {
        ReleaseTarget();
        g_dirty = true;
    }
}

static void Present() {
    if (!g_hwnd || !g_dib) {
        return;
    }
    POINT ptSrc = {0, 0};
    POINT ptDst = {g_winX + (int)std::lround(g_offX), g_winY + (int)std::lround(g_offY)};
    SIZE size = {g_bmpW, g_bmpH};
    BLENDFUNCTION bf = {};
    bf.BlendOp = AC_SRC_OVER;
    bf.SourceConstantAlpha = (BYTE)std::clamp((int)std::lround(g_alpha * 255.0), 0, 255);
    bf.AlphaFormat = AC_SRC_ALPHA;
    UpdateLayeredWindow(g_hwnd, nullptr, &ptDst, &size, g_memDC, &ptSrc, 0, &bf, ULW_ALPHA);
    if (UseLive()) {
        LiveSync();
    } else {
        LiveHide();
    }
}

// ===== Show / hide / per-frame animation =====

// k = 0 -> fully shown, k = 1 -> fully "hidden" state of the chosen animation.
static void ApplyAnimProgress(double k) {
    g_offX = k * g_animFromX;
    g_offY = k * g_animFromY;
    g_animScale = 1.0 + (g_animFromScale - 1.0) * k;
    g_alpha = g_animFadeOn ? std::clamp(1.0 - k, 0.0, 1.0) : 1.0;
}

static double AnimShowSec() {
    if (g_cfg.anim == AnimStyle::None || g_cfg.animMs <= 0) return 0.001;
    return g_cfg.animMs / 1000.0;
}

static double AnimHideSec() {
    return std::max(0.001, AnimShowSec() * 0.7);
}

// The scale (Pop up) or the clip (slides inside the frame) change what is drawn on every frame.
static bool NeedsRedrawPerFrame() {
    const bool slide = g_cfg.anim == AnimStyle::SlideBottom || g_cfg.anim == AnimStyle::SlideTop ||
                       g_cfg.anim == AnimStyle::SlideLeft || g_cfg.anim == AnimStyle::SlideRight;
    return g_cfg.anim == AnimStyle::Popup || (g_clipInner && slide);
}

static void ForceForeground(HWND h) {
    // The hotkey (a global input event) already grants foreground rights; the empty SendInput
    // covers the case where SetForegroundWindow would still be denied. No AttachThreadInput:
    // while sharing an input queue with the foreground app, a hung app would stall the launcher.
    // The hotkey normally grants the right to take the foreground, so try the plain call first.
    // The synthetic mouse event is only a fallback (it can make an auto-hide taskbar react).
    SetForegroundWindow(h);
    if (GetForegroundWindow() != h) {
        INPUT input{};
        input.type = INPUT_MOUSE;
        SendInput(1, &input, sizeof(INPUT));
        SetForegroundWindow(h);
    }
    BringWindowToTop(h);
    SetFocus(h);
}

// True when the foreground window covers its monitor and is not the desktop or taskbar (the
// usual heuristic for a focused fullscreen app: games, video players, F11 browsers). A few
// pixels of tolerance keep a maximized window from counting when it does not fully cover it.
static bool IsForegroundFullscreen() {
    HWND fg = GetForegroundWindow();
    if (!fg || fg == g_hwnd) {
        return false;
    }
    // A maximized window's rect includes the invisible resize border, so on a monitor whose
    // taskbar auto-hides it would pass the "covers the monitor" test below. A maximized window
    // is not fullscreen (F11 browsers and fullscreen games are not zoomed), so it is ruled out.
    if (IsZoomed(fg)) {
        return false;
    }
    // The shell windows (desktop, taskbar, Start menu) are never treated as fullscreen.
    wchar_t cls[64] = {};
    if (GetClassNameW(fg, cls, 64)) {
        if (lstrcmpW(cls, L"Progman") == 0 || lstrcmpW(cls, L"WorkerW") == 0 ||
            lstrcmpW(cls, L"Shell_TrayWnd") == 0 || lstrcmpW(cls, L"Shell_SecondaryTrayWnd") == 0 ||
            lstrcmpW(cls, L"Windows.UI.Core.CoreWindow") == 0 ||
            lstrcmpW(cls, L"XamlExplorerHostIslandWindow") == 0) {
            return false;
        }
    }

    RECT wr = {};
    if (!GetWindowRect(fg, &wr)) {
        return false;
    }
    HMONITOR mon = MonitorFromWindow(fg, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi = {};
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfoW(mon, &mi)) {
        return false;
    }
    // The window rect includes the invisible resize border; a few pixels of tolerance keep a
    // maximized window that does not hide the taskbar from counting as fullscreen.
    const int tol = 8;
    const RECT& m = mi.rcMonitor;
    return wr.left <= m.left + tol && wr.top <= m.top + tol &&
           wr.right >= m.right - tol && wr.bottom >= m.bottom - tol;
}

static void FinishHide() {
    if (g_frameTimerOn) {
        KillTimer(g_hwnd, TIMER_FRAME);
        g_frameTimerOn = false;
    }
    KillTimer(g_hwnd, TIMER_BLINK);
    KillTimer(g_hwnd, TIMER_COPY);
    KillTimer(g_hwnd, TIMER_CALC);
    KillTimer(g_hwnd, TIMER_CONFIRM);
    g_cmdArmed = -1;
    g_winListFresh = false;
    g_calcPending = false;
    ShowWindow(g_hwnd, SW_HIDE);
    LiveHide();
    g_vis = Vis::Hidden;
    g_lastHide = NowSec();
    ReleaseBackdrop();
    ReleaseResultLayouts();
    Sound::Suspend();
    MaybeReindexInBackground();  // changes detected while it was open
}

static void HideLauncher(bool restoreFocus = false) {
    if (g_vis == Vis::Hidden || g_vis == Vis::Hiding) {
        return;
    }
    g_vis = Vis::Hiding;
    g_visStart = NowSec();
    StartFrameTimer();

    // Closing with Esc / the shortcut: give the focus back to the window that had it. Otherwise
    // Windows picks the next window itself and sometimes activates the taskbar, which makes an
    // auto-hide taskbar pop up.
    if (restoreFocus && g_prevFg && g_prevFg != g_hwnd && IsWindow(g_prevFg) && !IsIconic(g_prevFg)) {
        wchar_t cls[64] = {};
        GetClassNameW(g_prevFg, cls, 64);
        if (lstrcmpW(cls, L"Shell_TrayWnd") != 0 && lstrcmpW(cls, L"Shell_SecondaryTrayWnd") != 0) {
            SetForegroundWindow(g_prevFg);
        }
    }
    g_prevFg = nullptr;
}

static void ShowLauncher() {
    if (!g_hwnd) {
        return;
    }
    {
        HWND fg = GetForegroundWindow();
        g_prevFg = (fg && fg != g_hwnd) ? fg : nullptr;
    }
    POINT pt = {};
    GetCursorPos(&pt);
    HMONITOR mon = MonitorFromPoint(pt, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFO mi = {};
    mi.cbSize = sizeof(mi);
    GetMonitorInfoW(mon, &mi);

    double monScale = MonitorScale(mon) * g_cfg.uiSize;
    if (!EnsureSurface(monScale)) {
        return;
    }
    LoadPalette();
    // With live acrylic on Windows 11, DWM rounds the corners (fixed radius ~8 px).
    {
        const float ur = FluidShell::FrameActive() ? (float)(FluidShell::FrameRadiusDip() / g_cfg.uiSize)
                                                   : (float)g_cfg.cornerRadius;
        if (UseLive() && g_liveWin11) {
            kRadius = ur <= 1.f ? 0.f : (ur <= 6.f ? 4.f : 8.f);
            LiveApplyCorners(ur <= 1.f ? 1 : (ur <= 6.f ? 3 : 2));
        } else {
            kRadius = ur;
        }
    }
    if (!EnsureTarget()) {
        return;
    }
    g_matchBrush->SetColor(&g_pal.match);

    // ---- Placement preset and list direction ----
    g_vPct = g_cfg.verticalPct;
    g_hPct = g_cfg.horizPct;
    bool flip = false;
    switch (g_cfg.preset) {
        case PosPreset::Top:    g_hPct = 50; g_vPct = 0; break;
        case PosPreset::Bottom: g_hPct = 50; g_vPct = 100; flip = true; break;
        case PosPreset::Left:   g_hPct = 0; break;
        case PosPreset::Right:  g_hPct = 100; break;
        case PosPreset::Center: g_hPct = 50; g_vPct = 50; break;
        default: break;
    }
    if (g_cfg.listDir == ListDir::Up) {
        flip = true;
    } else if (g_cfg.listDir == ListDir::Down) {
        flip = false;
    } else if (g_vPct >= 60) {
        flip = true;
    }
    g_flip = flip;
    g_hAlign = std::clamp(g_hPct, 0, 100) / 100.0;
    // Fluid Shell: dock inside the frame / bar. With the frame on, docked edges are flat with flares (notch style).
    RECT shellInner = {};
    const bool shellHasInner = FluidShell::GetInnerRect(mi.rcMonitor, &shellInner);
    const bool shellFrame = shellHasInner && FluidShell::FrameActive();
    const bool flatOk = g_cfg.notch || shellFrame;
    g_flatTop = flatOk && !g_flip && g_vPct <= 0;
    g_flatBottom = flatOk && g_flip && g_vPct >= 100;
    g_flatLeft = flatOk && g_hPct <= 0;
    g_flatRight = flatOk && g_hPct >= 100;
    g_clipInner = shellFrame;  // the card is only visible inside the frame (it emerges from it)
    g_clipRect = shellInner;

    g_text.clear();
    g_caret = g_anchor = 0;
    g_inputScroll = 0;
    g_caretOn = true;
    g_copiedAt = -1e9;
    g_calc = Calc::Result();
    g_calcDisplay.clear();
    g_calcActive = false;
    g_calcPending = false;
    g_calcHistSel = -1;
    g_histScroll = 0;
    if (g_hwnd) KillTimer(g_hwnd, TIMER_COPY);
    if (g_hwnd) KillTimer(g_hwnd, TIMER_CALC);
    g_lastMouse = {-1, -1};
    g_sel = 0;
    g_scrollTarget = 0;
    g_detailsOpen = false;  // the details panel starts closed on each open
    g_detailPos = g_detailTarget = 0;
    g_hoverAction = -1;
    g_hoverReindex = false;
    RunSearch();
    g_sel = DefaultSel();
    ResetScroll();
    UpdateTargets(true, /*followSelection=*/true);

    // ---- Placement ----
    // The block (card + details panel) is positioned inside the work area with the horizontal /
    // vertical percentages and the edge margin. 0 % / 100 % are glued to the edges (minus margin).
    const double ss = g_scale;
    const double edge = ((g_cfg.notch || shellFrame) ? 0 : g_cfg.edgeMargin) * ss;
    const RECT& wa = shellHasInner ? shellInner
                                   : ((g_cfg.dockScreenEdge || g_cfg.notch) ? mi.rcMonitor : mi.rcWork);
    const double workL = (double)wa.left;
    const double workW = (double)(wa.right - wa.left);
    const double innerPx = (kWidth + kPanelGap + kPanelW) * ss;
    const double contentLeft = workL + edge + (workW - 2 * edge - innerPx) * g_hAlign;
    g_winX = (int)std::lround(contentLeft - kMargin * ss);

    g_workTop = (double)wa.top;
    g_workBottom = (double)wa.bottom;
    const double workH = g_workBottom - g_workTop;
    const double barH = kBarH * ss;
    const double vf = std::clamp(g_vPct, 0, 100) / 100.0;
    if (g_flip) {
        g_anchorBottom = g_workBottom - edge - (workH - 2 * edge - barH) * (1.0 - vf);
        g_anchorTop = g_anchorBottom - barH;
    } else {
        g_anchorTop = g_workTop + edge + (workH - 2 * edge - barH) * vf;
        g_anchorBottom = g_anchorTop + barH;
    }

    const double expandedCardH = kExpandedMinH * ss;
    if (g_flip) {
        g_winY = (int)std::lround(g_anchorBottom - expandedCardH - kMargin * ss);
    } else {
        g_winY = (int)std::lround(g_anchorTop - kMargin * ss);
    }
    // Only the vertical position is kept on the monitor; the card is placed from absolute
    // coordinates, and the transparent margin of the surface may hang off the edge.
    if (g_winY + g_bmpH > mi.rcMonitor.bottom) g_winY = mi.rcMonitor.bottom - g_bmpH;
    if (g_winY < mi.rcMonitor.top) g_winY = mi.rcMonitor.top;

    // ---- Open animation start state ----
    g_animFromX = g_animFromY = 0.0;
    g_animFromScale = 1.0;
    g_animFadeOn = g_cfg.animFade || g_cfg.anim == AnimStyle::Fade || g_cfg.anim == AnimStyle::Popup;
    {
        float mox = 0, moy = 0;
        MainOrigin(mox, moy);
        const double cardL = g_winX + mox;
        const double cardT = g_winY + moy;
        const double cardW = kWidth * ss;
        const double cardH = g_curH * ss;
        const double dist = g_cfg.slideDist * ss;  // 0 = from the screen edge
        switch (g_cfg.anim) {
            case AnimStyle::SlideBottom:
                g_animFromY = dist > 0 ? dist : (mi.rcMonitor.bottom - cardT) + 2;
                break;
            case AnimStyle::SlideTop:
                g_animFromY = -(dist > 0 ? dist : (cardT + cardH - mi.rcMonitor.top) + 2);
                break;
            case AnimStyle::SlideLeft:
                g_animFromX = -(dist > 0 ? dist : (cardL + cardW - mi.rcMonitor.left) + 2);
                break;
            case AnimStyle::SlideRight:
                g_animFromX = dist > 0 ? dist : (mi.rcMonitor.right - cardL) + 2;
                break;
            case AnimStyle::Popup:
                g_animFromScale = 0.9;
                break;
            default:
                break;
        }
    }

    // Acrylic: capture the desktop now, with the window still hidden.
    PrepareBackdrop();
    if (UseLive()) {
        LiveApplyAccent();
    }

    g_vis = Vis::Showing;
    g_visStart = NowSec();
    g_shownAt = g_visStart;
    g_animK = 1.0;  // start the opening spring from "hidden"
    g_animV = 0.0;
    ApplyAnimProgress(1.0);

    Render();
    g_dirty = false;
    Present();
    ShowWindow(g_hwnd, SW_SHOW);
    ForceForeground(g_hwnd);
    Sound::Resume();
    Sound::OnOpen();

    SetTimer(g_hwnd, TIMER_BLINK, 530, nullptr);
    StartFrameTimer();

    if (!g_indexing && ShouldReindexOnOpen()) {
        StartIndex();
    }
}

static void ToggleLauncher() {
    if (g_vis == Vis::Showing || g_vis == Vis::Shown) {
        HideLauncher(true);
    } else {
        ShowLauncher();
    }
}

static void OnFrame() {
    double t = NowSec();
    double dt = std::min(0.05, t - g_lastFrame);
    g_lastFrame = t;
    bool active = false;
    bool present = false;

    if (g_vis == Vis::Showing) {
        // Only the Pop up style may overshoot; slides settle without bouncing.
        const double zeta = (g_cfg.anim == AnimStyle::Popup) ? g_cfg.bounceZeta : 1.0;
        const bool moving = SpringTo(g_animK, g_animV, 0.0, zeta, AnimShowSec(), dt, 0.0015, 0.02);
        if (g_cfg.anim != AnimStyle::Popup && g_animK < 0.0) {
            g_animK = 0.0;
            g_animV = 0.0;
        }
        if (moving) {
            active = true;
        } else {
            g_vis = Vis::Shown;
        }
        ApplyAnimProgress(g_animK);
        if (NeedsRedrawPerFrame()) g_dirty = true;
        present = true;
    } else if (g_vis == Vis::Hiding) {
        SpringTo(g_animK, g_animV, 1.0, 1.0, AnimHideSec(), dt, 0.0015, 0.02);
        if (g_animK >= 0.985) {
            FinishHide();
            return;
        }
        ApplyAnimProgress(std::clamp(g_animK, 0.0, 1.0));
        if (NeedsRedrawPerFrame()) g_dirty = true;
        active = true;
        present = true;
    }

    if (g_vis != Vis::Hidden) {
        if (Smooth(g_selPos, g_selTarget, 28.0, dt, 0.002)) { active = true; g_dirty = true; }
        if (Smooth(g_scrollPos, g_scrollTarget, 22.0, dt, 0.002)) { active = true; g_dirty = true; }
        if (SpringTo(g_curH, g_curHV, g_targetH, 0.9, 0.22, dt, 0.3, 4.0)) { active = true; g_dirty = true; }
        if (SpringTo(g_detailPos, g_detailV, g_detailTarget, 0.9, 0.25, dt, 0.003, 0.05)) { active = true; g_dirty = true; }
        if (g_indexing) { active = true; g_dirty = true; }  // keeps the footer icon spinning
    }

    if (g_dirty) {
        g_dirty = false;
        Render();
        present = true;
    }
    if (present) {
        Present();
    }
    if (!active && !g_dirty && g_frameTimerOn) {
        KillTimer(g_hwnd, TIMER_FRAME);
        g_frameTimerOn = false;
    }
}

// ===== Launching =====
// Records a use: counter (for "Suggestions") and timestamp (for "Recent").
static void RecordUse(AppEntry& a) {
    a.uses++;
    a.lastUsed = NowStamp();
    Wh_SetIntValue(a.usageKey.c_str(), a.uses);
    Wh_SetIntValue((a.usageKey + L"t").c_str(), a.lastUsed);
    g_detailsCache.erase(a.id);  // "Uses" / "Last used" change
}

// Opens a desktop app through its real target. Resolving "shell:AppsFolder\{GUID}\..." from
// this 32-bit process redirects the FOLDERID_ProgramFilesX64 GUID to "C:\Program Files (x86)",
// so 64-bit apps installed in "C:\Program Files" fail to launch. System.Link.TargetParsingPath
// holds the real, unredirected path and is used instead. Store (MSIX) apps use their AUMID.
// ===== Window switcher =====

static bool IsWindowCloaked(HWND h) {
    typedef HRESULT(WINAPI * DwmGetWindowAttribute_t)(HWND, DWORD, PVOID, DWORD);
    static DwmGetWindowAttribute_t fn = [] {
        HMODULE m = LoadLibraryExW(L"dwmapi.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
        return m ? (DwmGetWindowAttribute_t)GetProcAddress(m, "DwmGetWindowAttribute") : nullptr;
    }();
    DWORD cloaked = 0;
    return fn && SUCCEEDED(fn(h, 14 /*DWMWA_CLOAKED*/, &cloaked, sizeof(cloaked))) && cloaked != 0;
}

static std::wstring ProcessImagePath(DWORD pid) {
    std::wstring r;
    HANDLE p = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (p) {
        wchar_t buf[MAX_PATH * 2] = {};
        DWORD n = ARRAYSIZE(buf);
        if (QueryFullProcessImageNameW(p, 0, buf, &n)) r.assign(buf, n);
        CloseHandle(p);
    }
    return r;
}

struct WinEnumCtx {
    std::vector<AppEntry>* out;
    int z;
};

static BOOL CALLBACK EnumWinProc(HWND h, LPARAM lp) {
    WinEnumCtx* ctx = (WinEnumCtx*)lp;
    if (h == g_hwnd || h == g_liveWnd || h == g_livePanel) return TRUE;
    if (!IsWindowVisible(h)) return TRUE;
    if (GetWindow(h, GW_OWNER)) return TRUE;
    const LONG_PTR ex = GetWindowLongPtrW(h, GWL_EXSTYLE);
    if ((ex & WS_EX_TOOLWINDOW) && !(ex & WS_EX_APPWINDOW)) return TRUE;
    if (IsWindowCloaked(h)) return TRUE;  // other virtual desktops, suspended Store apps...

    wchar_t title[256] = {};
    if (GetWindowTextW(h, title, ARRAYSIZE(title)) <= 0) return TRUE;
    wchar_t cls[64] = {};
    GetClassNameW(h, cls, ARRAYSIZE(cls));
    if (lstrcmpW(cls, L"Progman") == 0 || lstrcmpW(cls, L"Windows.UI.Core.CoreWindow") == 0) return TRUE;

    DWORD pid = 0;
    GetWindowThreadProcessId(h, &pid);
    const std::wstring path = ProcessImagePath(pid);

    AppEntry a;
    a.name = title;
    a.folded = FoldString(a.name);
    a.id = L"@win:" + std::to_wstring((unsigned long long)(uintptr_t)h);
    a.isWin = true;
    a.winHandle = (uintptr_t)h;
    a.cmdId = ctx->z++;  // z-order: most recently used first
    if (!path.empty()) {
        size_t sl = path.find_last_of(L"\\/");
        std::wstring stem = (sl == std::wstring::npos) ? path : path.substr(sl + 1);
        if (stem.size() > 4 && LowerAscii(stem.substr(stem.size() - 4)) == L".exe") stem.resize(stem.size() - 4);
        a.sub = stem;
    }

    // Icon: the window's own icon first, the program's icon as a fallback.
    HICON hi = nullptr;
    DWORD_PTR res = 0;
    if (SendMessageTimeoutW(h, WM_GETICON, ICON_BIG, 0, SMTO_ABORTIFHUNG, 40, &res) && res) hi = (HICON)res;
    if (!hi && SendMessageTimeoutW(h, WM_GETICON, ICON_SMALL2, 0, SMTO_ABORTIFHUNG, 40, &res) && res) {
        hi = (HICON)res;
    }
    if (!hi) hi = (HICON)GetClassLongPtrW(h, GCLP_HICON);
    Pix p;
    bool haveIcon = hi && HIconToPix(hi, p) && HasVisiblePixels(p);
    if (!haveIcon && !path.empty()) {
        p = Pix();
        haveIcon = GetFileIconPix(path, p) && HasVisiblePixels(p);
    }
    if (haveIcon) {
        a.iconW = p.w;
        a.iconH = p.h;
        a.iconPx = std::move(p.px);
    }
    ctx->out->push_back(std::move(a));
    return TRUE;
}

// Window entries always sit at the tail of g_apps; they are rebuilt each time the window mode is
// entered after the launcher was opened.
static void RefreshWindowEntries() {
    while (!g_apps.empty() && g_apps.back().isWin) {
        SafeRelease(g_apps.back().bmp);
        g_apps.pop_back();
    }
    std::vector<AppEntry> found;
    WinEnumCtx ctx = {&found, 0};
    EnumWindows(EnumWinProc, (LPARAM)&ctx);
    for (auto& a : found) g_apps.push_back(std::move(a));
}

static void BuildWindowResults() {
    if (!g_winListFresh) {
        RefreshWindowEntries();
        g_winListFresh = true;
    }
    std::vector<SearchResult> out;
    for (size_t i = 0; i < g_apps.size(); ++i) {
        const AppEntry& a = g_apps[i];
        if (!a.isWin) continue;
        int best = 100000 - a.cmdId;  // nothing typed: keep the z-order
        if (!g_tokens.empty()) {
            const std::wstring subFolded = FoldString(a.sub);
            int total = 0;
            bool ok = true;
            for (const auto& tok : g_tokens) {
                int sc = std::max(ScoreToken(a.name, a.folded, tok, nullptr),
                                  a.sub.empty() ? 0 : ScoreToken(a.sub, subFolded, tok, nullptr));
                if (sc <= 0) {
                    ok = false;
                    break;
                }
                total += sc;
            }
            if (!ok) continue;
            best = total / (int)g_tokens.size();
        }
        SearchResult r;
        r.app = (int)i;
        r.score = best;
        out.push_back(r);
    }
    std::sort(out.begin(), out.end(), [](const SearchResult& x, const SearchResult& y) {
        if (x.score != y.score) return x.score > y.score;
        return g_apps[x.app].cmdId < g_apps[y.app].cmdId;
    });
    g_results = out;
}

static void ActivateWindow(uintptr_t handle) {
    HWND h = (HWND)handle;
    HideLauncher();  // no focus restore: the target window takes over
    if (!IsWindow(h)) return;
    if (IsIconic(h)) ShowWindow(h, SW_RESTORE);
    if (!SetForegroundWindow(h)) SwitchToThisWindow(h, TRUE);
}

// ===== Helpers for the system commands =====

static void SendVk(WORD vk, int times) {
    for (int i = 0; i < times; ++i) {
        INPUT in[2] = {};
        in[0].type = INPUT_KEYBOARD;
        in[0].ki.wVk = vk;
        in[1] = in[0];
        in[1].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(2, in, sizeof(INPUT));
    }
}

static void SendWinD() {
    INPUT in[4] = {};
    for (int i = 0; i < 4; ++i) in[i].type = INPUT_KEYBOARD;
    in[0].ki.wVk = VK_LWIN;
    in[1].ki.wVk = 'D';
    in[2].ki.wVk = 'D';
    in[2].ki.dwFlags = KEYEVENTF_KEYUP;
    in[3].ki.wVk = VK_LWIN;
    in[3].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(4, in, sizeof(INPUT));
}

static void ToggleDarkMode() {
    HKEY k = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0,
                      KEY_QUERY_VALUE | KEY_SET_VALUE | KEY_WOW64_64KEY, &k) != ERROR_SUCCESS) {
        return;
    }
    DWORD cur = 1, sz = sizeof(cur);
    RegQueryValueExW(k, L"AppsUseLightTheme", nullptr, nullptr, (BYTE*)&cur, &sz);
    const DWORD next = cur ? 0 : 1;  // flip both the apps and the system theme
    RegSetValueExW(k, L"AppsUseLightTheme", 0, REG_DWORD, (const BYTE*)&next, sizeof(next));
    RegSetValueExW(k, L"SystemUsesLightTheme", 0, REG_DWORD, (const BYTE*)&next, sizeof(next));
    RegCloseKey(k);
    SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)L"ImmersiveColorSet", SMTO_ABORTIFHUNG, 300,
                        nullptr);
}

// The key-up of Enter would wake the display again right away, so it is switched off a moment later.
static DWORD WINAPI DisplayOffThread(LPVOID) {
    Sleep(600);
    SendMessageTimeoutW(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, 2, SMTO_ABORTIFHUNG, 500, nullptr);
    return 0;
}

// Runs a power command. Shutdown / Restart / Logout need a second Enter (4 s window) when the
// setting is on. Hibernation-safe sleep and the 64-bit shutdown.exe are reached from this 32-bit
// process the usual way (SetSuspendState from powrprof.dll, shutdown.exe from the redirected System32).
static void RunPowerCommand(int cmd, int appIdx) {
    const bool destructive =
        cmd == CMD_SHUTDOWN || cmd == CMD_RESTART || cmd == CMD_LOGOUT || cmd == CMD_RECYCLE;
    if (destructive && g_cfg.confirmPower) {
        if (g_cmdArmed != appIdx || NowSec() - g_cmdArmedAt > 4.0) {
            g_cmdArmed = appIdx;
            g_cmdArmedAt = NowSec();
            SetTimer(g_hwnd, TIMER_CONFIRM, 4000, nullptr);
            MarkDirty();
            return;
        }
    }
    g_cmdArmed = -1;
    HideLauncher();
    switch (cmd) {
        case CMD_SHUTDOWN:
            ShellExecuteW(nullptr, L"open", L"shutdown.exe", L"/s /t 0", nullptr, SW_HIDE);
            break;
        case CMD_RESTART:
            ShellExecuteW(nullptr, L"open", L"shutdown.exe", L"/r /t 0", nullptr, SW_HIDE);
            break;
        case CMD_LOGOUT:
            ExitWindowsEx(EWX_LOGOFF, 0);
            break;
        case CMD_LOCK:
            LockWorkStation();
            break;
        case CMD_HIBERNATE:
        case CMD_SLEEP: {
            typedef BOOLEAN(WINAPI * SetSuspendState_t)(BOOLEAN, BOOLEAN, BOOLEAN);
            HMODULE m = LoadLibraryExW(L"powrprof.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
            auto fn = m ? (SetSuspendState_t)GetProcAddress(m, "SetSuspendState") : nullptr;
            if (fn) fn(cmd == CMD_HIBERNATE ? TRUE : FALSE, FALSE, FALSE);
            if (m) FreeLibrary(m);
            break;
        }
        case CMD_MUTE:
            SendVk(VK_VOLUME_MUTE, 1);
            break;
        case CMD_VOLUP:
            SendVk(VK_VOLUME_UP, 5);
            break;
        case CMD_VOLDOWN:
            SendVk(VK_VOLUME_DOWN, 5);
            break;
        case CMD_PLAYPAUSE:
            SendVk(VK_MEDIA_PLAY_PAUSE, 1);
            break;
        case CMD_NEXT:
            SendVk(VK_MEDIA_NEXT_TRACK, 1);
            break;
        case CMD_PREV:
            SendVk(VK_MEDIA_PREV_TRACK, 1);
            break;
        case CMD_DARKMODE:
            ToggleDarkMode();
            break;
        case CMD_DISPLAYOFF: {
            HANDLE th = CreateThread(nullptr, 0, DisplayOffThread, nullptr, 0, nullptr);
            if (th) CloseHandle(th);
            break;
        }
        case CMD_SHOWDESKTOP:
            SendWinD();
            break;
        case CMD_RECYCLE:
            SHEmptyRecycleBinW(nullptr, nullptr, SHERB_NOCONFIRMATION | SHERB_NOPROGRESSUI | SHERB_NOSOUND);
            break;
    }
}

static void LaunchApp(int appIdx) {
    if (appIdx < 0 || appIdx >= (int)g_apps.size()) {
        return;
    }
    AppEntry& a = g_apps[appIdx];
    AllowSetForegroundWindow(ASFW_ANY);

    if (a.isCmd) {
        RunPowerCommand(a.cmdId, appIdx);
        return;
    }

    if (a.isWin) {
        ActivateWindow(a.winHandle);
        return;
    }

    if (a.desktop) {
        // Open the shortcut itself so its arguments, working folder and "run as admin" flag apply.
        const std::wstring dir = a.id.substr(0, a.id.find_last_of(L'\\'));
        ShellExecuteW(nullptr, L"open", a.id.c_str(), nullptr, dir.empty() ? nullptr : dir.c_str(),
                      SW_SHOWNORMAL);
        RecordUse(a);
        HideLauncher();
        return;
    }

    std::wstring file;
    std::wstring args;
    if (!IsPackagedId(a.id)) {
        IShellItem2* item = nullptr;
        std::wstring parse = a.desktop ? a.id : L"shell:AppsFolder\\" + a.id;
        if (SUCCEEDED(SHCreateItemFromParsingName(parse.c_str(), nullptr, IID_PPV_ARGS(&item))) && item) {
            file = ItemString(item, L"System.Link.TargetParsingPath");
            args = ItemString(item, L"System.Link.Arguments");
            item->Release();
        }
        if (file.empty()) {
            file = PathFromAppId(a.id);
        }
    }

    // Some AppsFolder entries resolve to a shell namespace GUID rather than a file (File Explorer's
    // target is "::{52205FD8-...}", the "This PC" folder), which cannot be started as a file. Drop
    // it so the AUMID route below is used instead.
    if (file.size() >= 2 && file[0] == L':' && file[1] == L':') {
        file.clear();
    }

    if (!file.empty()) {
        if (IsUnderWindowsDir(file)) {
            // A System32 target must not be resolved by this 32-bit process: it would be
            // redirected to SysWOW64 and the tool (or a delay-loaded DLL) would not be found.
            // Disabling the redirection around the call is not safe, because a failed
            // delay-load stays failed for the rest of the process. Let the 64-bit shell resolve
            // the AppsFolder ID instead (explorer.exe is not redirected); it also keeps the
            // shortcut's arguments, working folder and elevation.
            wchar_t win[MAX_PATH];
            UINT n = GetWindowsDirectoryW(win, MAX_PATH);
            if (n && n < MAX_PATH) {
                const std::wstring explorer = std::wstring(win) + L"\\explorer.exe";
                const std::wstring arg = L"shell:AppsFolder\\" + a.id;
                ShellExecuteW(nullptr, L"open", explorer.c_str(), arg.c_str(), nullptr, SW_SHOWNORMAL);
            }
        } else {
            // Start the app in its own folder, not in Windhawk's directory (portable apps and
            // some games read files relative to the working directory).
            std::wstring dir = file.substr(0, file.find_last_of(L'\\'));
            ShellExecuteW(nullptr, L"open", file.c_str(), args.empty() ? nullptr : args.c_str(),
                          dir.empty() ? nullptr : dir.c_str(), SW_SHOWNORMAL);
        }
    } else {
        std::wstring url = L"shell:AppsFolder\\" + a.id;
        ShellExecuteW(nullptr, L"open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
    }
    RecordUse(a);
    HideLauncher();
}

static void LaunchSelected() {
    if (g_results.empty() || g_sel < 0 || g_sel >= (int)g_results.size()) {
        return;
    }
    LaunchApp(g_results[g_sel].app);
}

// ===== Details panel actions =====

static void CopyTextToClipboard(const std::wstring& s) {
    if (!OpenClipboard(g_hwnd)) return;
    EmptyClipboard();
    HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, (s.size() + 1) * sizeof(wchar_t));
    wchar_t* p = h ? (wchar_t*)GlobalLock(h) : nullptr;
    if (p) {
        memcpy(p, s.c_str(), (s.size() + 1) * sizeof(wchar_t));
        GlobalUnlock(h);
        if (SetClipboardData(CF_UNICODETEXT, h)) h = nullptr;  // the clipboard owns it now
    }
    if (h) GlobalFree(h);
    CloseClipboard();
}

static void RunAction(int actionId, int appIdx) {
    if (appIdx < 0 || appIdx >= (int)g_apps.size()) {
        return;
    }
    AppEntry& a = g_apps[appIdx];
    const AppDetails& d = GetDetails(a);
    if (!ActionAvailable(actionId, a, d)) {
        return;  // e.g. "Run as administrator" on a Store app
    }
    const std::wstring target = d.target;  // copy: RecordUse invalidates the cache

    switch (actionId) {
        case ACT_OPEN:
            LaunchApp(appIdx);
            return;

        case ACT_ADMIN: {
            AllowSetForegroundWindow(ASFW_ANY);
            std::wstring dir = target.substr(0, target.find_last_of(L'\\'));
            // Keep the shortcut's arguments, or a profile shortcut would open the default one.
            HINSTANCE r = ShellExecuteW(nullptr, L"runas", target.c_str(),
                                        d.args.empty() ? nullptr : d.args.c_str(),
                                        dir.empty() ? nullptr : dir.c_str(), SW_SHOWNORMAL);
            if ((INT_PTR)r > 32) {
                RecordUse(a);
            }
            HideLauncher();
            return;
        }

        case ACT_LOCATION: {
            std::wstring args = L"/select,\"" + target + L"\"";
            ShellExecuteW(nullptr, L"open", L"explorer.exe", args.c_str(), nullptr, SW_SHOWNORMAL);
            HideLauncher();
            return;
        }

        case ACT_COPYPATH:
            CopyTextToClipboard(target);
            HideLauncher();
            return;

        case ACT_PROPS: {
            SHELLEXECUTEINFOW sei = {};
            sei.cbSize = sizeof(sei);
            sei.fMask = SEE_MASK_INVOKEIDLIST;
            sei.lpVerb = L"properties";
            sei.lpFile = target.c_str();
            sei.nShow = SW_SHOWNORMAL;
            ShellExecuteExW(&sei);
            HideLauncher();
            return;
        }

        case ACT_FORGET:
            a.uses = 0;
            a.lastUsed = 0;
            Wh_SetIntValue(a.usageKey.c_str(), 0);
            Wh_SetIntValue((a.usageKey + L"t").c_str(), 0);
            g_detailsCache.erase(a.id);
            RunSearch();
            g_sel = std::min(g_sel, std::max(0, (int)g_results.size() - 1));
            UpdateTargets(false, /*followSelection=*/true);
            MarkDirty();
            return;
    }
}

static void RunActionOnSelection(int actionId) {
    if (g_results.empty() || g_sel < 0 || g_sel >= (int)g_results.size()) {
        return;
    }
    RunAction(actionId, g_results[g_sel].app);
}

static void SetDetailsOpen(bool open) {
    if (open && (g_results.empty() || SelIsCmd())) {
        return;  // no selected app (or a power command), nothing to detail
    }
    g_detailsOpen = open;
    g_hoverAction = -1;
    Sound::OnPanel(open);
    UpdateTargets(false, /*followSelection=*/false);
    MarkDirty();
}

static bool IsDetailsKey(WPARAM vk, bool ctrl, bool shift) {
    if (shift) return false;
    switch (g_cfg.detailsKey) {
        case DetailsKey::CtrlI:     return ctrl && vk == 'I';
        case DetailsKey::CtrlK:     return ctrl && vk == 'K';
        case DetailsKey::CtrlSpace: return ctrl && vk == VK_SPACE;
        case DetailsKey::F4:        return !ctrl && vk == VK_F4;
    }
    return false;
}

// ===== Text editing =====

static bool CtrlDown() { return (GetKeyState(VK_CONTROL) & 0x8000) != 0; }
static bool ShiftDown() { return (GetKeyState(VK_SHIFT) & 0x8000) != 0; }

static int PrevWord(int pos) {
    while (pos > 0 && g_text[pos - 1] == L' ') --pos;
    while (pos > 0 && g_text[pos - 1] != L' ') --pos;
    return pos;
}

static int NextWord(int pos) {
    int n = (int)g_text.size();
    while (pos < n && g_text[pos] != L' ') ++pos;
    while (pos < n && g_text[pos] == L' ') ++pos;
    return pos;
}

static void MoveCaret(int pos, bool extend) {
    pos = std::clamp(pos, 0, (int)g_text.size());
    g_caret = pos;
    if (!extend) g_anchor = pos;
    ResetBlink();
    MarkDirty();
}

static void ReplaceSelection(const std::wstring& s) {
    int a = std::min(g_anchor, g_caret);
    int b = std::max(g_anchor, g_caret);
    std::wstring t = g_text.substr(0, a) + s + g_text.substr(b);
    if (t.size() > 200) {
        return;
    }
    g_text = t;
    g_caret = g_anchor = a + (int)s.size();
    OnTextChanged();
}

static void CopySelection(bool cut) {
    int a = std::min(g_anchor, g_caret);
    int b = std::max(g_anchor, g_caret);
    if (a == b) return;
    CopyTextToClipboard(g_text.substr(a, b - a));
    if (cut) ReplaceSelection(L"");
}

static void PasteClipboard() {
    if (!OpenClipboard(g_hwnd)) return;
    std::wstring s;
    HANDLE h = GetClipboardData(CF_UNICODETEXT);
    if (h) {
        const wchar_t* p = (const wchar_t*)GlobalLock(h);
        if (p) {
            s = p;
            GlobalUnlock(h);
        }
    }
    CloseClipboard();
    for (auto& c : s) {
        if (c == L'\r' || c == L'\n' || c == L'\t') c = L' ';
    }
    if (!s.empty()) {
        ReplaceSelection(s);
        Sound::OnKey();
    }
}

static bool HandleKeyDown(WPARAM vk) {
    const bool ctrl = CtrlDown();
    const bool shift = ShiftDown();
    const int len = (int)g_text.size();
    const bool hasSel = g_anchor != g_caret;

    // Details panel: shortcut to show/hide it, and direct keyboard actions
    if (IsDetailsKey(vk, ctrl, shift)) {
        SetDetailsOpen(!g_detailsOpen);
        return true;
    }
    if (ctrl && vk == VK_RETURN) {
        RunActionOnSelection(shift ? ACT_ADMIN : ACT_LOCATION);
        return true;
    }
    if (ctrl && vk == 'P' && !shift) {
        RunActionOnSelection(ACT_PROPS);
        return true;
    }
    if (ctrl && shift && vk == 'C') {
        RunActionOnSelection(ACT_COPYPATH);
        return true;
    }
    if (ctrl && shift && vk == 'R') {
        // With the calculation history on screen this removes an entry (the highlighted one) or,
        // when nothing is highlighted, clears the whole history. Otherwise it forgets the app.
        if (CalcHistoryVisible()) {
            if (g_calcHistSel >= 0) {
                DeleteCalcHistory(g_calcHistSel);
            } else {
                ClearCalcHistory();
            }
            return true;
        }
        RunActionOnSelection(ACT_FORGET);
        return true;
    }
    if (ctrl && !shift && vk == 'R') {
        ForceReindex();
        return true;
    }

    switch (vk) {
        case VK_ESCAPE:
            if (g_detailsOpen) {
                SetDetailsOpen(false);  // the panel is closed first; another Esc closes the bar
            } else {
                HideLauncher(true);
            }
            return true;
        case VK_RETURN:
            // If the debounced calculation has not run yet, run it now so Enter is immediate.
            if (g_calcPending) {
                if (g_hwnd) KillTimer(g_hwnd, TIMER_CALC);
                g_calcPending = false;
                UpdateCalc();
                RunSearch();
                UpdateTargets(false, /*followSelection=*/true);
            }
            // A highlighted history row inserts its result into the expression. This works for any
            // recognised maths text, valid or still being composed (e.g. "2+2+").
            if (CalcHistoryVisible() && g_calcHistSel >= 0 && g_calcHistSel < (int)g_calcHist.size()) {
                InsertCalcHistory(g_calcHistSel);
                return true;
            }
            // A calculation owns Enter while there is no app result to open: copy the result and
            // keep the bar open so it can be refined or opened again.
            if (CalcOk() && g_results.empty()) {
                AddCalcHistory(g_text, g_calcDisplay, g_calc.insertable);
                SetCalcAns(g_calc.value);
                CopyTextToClipboard(CalcClipboardText());
                g_copiedAt = NowSec();
                g_histScroll = 0;
                g_calcHistSel = -1;
                SetTimer(g_hwnd, TIMER_COPY, 1400, nullptr);
                UpdateTargets(false, /*followSelection=*/false);
                MarkDirty();
                return true;
            }
            LaunchSelected();
            return true;
        case VK_DOWN:
            if (CalcHistoryVisible()) {
                if (g_calcHistSel < (int)g_calcHist.size() - 1) {
                    ++g_calcHistSel;
                    EnsureHistSelVisible();
                    MarkDirty();
                }
                return true;
            }
            SelectDelta(1);
            return true;
        case VK_UP:
            if (CalcHistoryVisible() && g_calcHistSel >= 0) {
                --g_calcHistSel;
                if (g_calcHistSel < 0) {
                    g_histScroll = 0;
                } else {
                    EnsureHistSelVisible();
                }
                MarkDirty();
                return true;
            }
            SelectDelta(-1);
            return true;
        case VK_TAB:
            // With a history row selected, Tab pulls its original expression into the field so it
            // can be edited (replacing whatever was typed). Otherwise it cycles the selection.
            if (CalcHistoryVisible() && g_calcHistSel >= 0 &&
                g_calcHistSel < (int)g_calcHist.size()) {
                EditCalcHistoryOp(g_calcHistSel);
                return true;
            }
            SelectDelta(shift ? -1 : 1);
            return true;
        case VK_NEXT:
            SelectDelta(std::max(1, VisibleRows()));
            return true;
        case VK_PRIOR:
            SelectDelta(-std::max(1, VisibleRows()));
            return true;
        case VK_LEFT:
            if (hasSel && !shift) {
                MoveCaret(std::min(g_anchor, g_caret), false);
            } else {
                MoveCaret(ctrl ? PrevWord(g_caret) : g_caret - 1, shift);
            }
            return true;
        case VK_RIGHT:
            if (hasSel && !shift) {
                MoveCaret(std::max(g_anchor, g_caret), false);
            } else {
                MoveCaret(ctrl ? NextWord(g_caret) : g_caret + 1, shift);
            }
            return true;
        case VK_HOME:
            MoveCaret(0, shift);
            return true;
        case VK_END:
            MoveCaret(len, shift);
            return true;
        case VK_BACK:
            if (hasSel) {
                ReplaceSelection(L"");
                Sound::OnErase();
            } else if (g_caret > 0) {
                g_anchor = ctrl ? PrevWord(g_caret) : g_caret - 1;
                ReplaceSelection(L"");
                Sound::OnErase();
            }
            return true;
        case VK_DELETE:
            if (hasSel) {
                ReplaceSelection(L"");
                Sound::OnErase();
            } else if (g_caret < len) {
                g_anchor = ctrl ? NextWord(g_caret) : g_caret + 1;
                ReplaceSelection(L"");
                Sound::OnErase();
            }
            return true;
        case 'A':
            if (ctrl) {
                g_anchor = 0;
                g_caret = len;
                ResetBlink();
                MarkDirty();
                return true;
            }
            break;
        case 'C':
            if (ctrl) {
                CopySelection(false);
                return true;
            }
            break;
        case 'X':
            if (ctrl) {
                CopySelection(true);
                return true;
            }
            break;
        case 'V':
            if (ctrl) {
                PasteClipboard();
                return true;
            }
            break;
    }
    return false;
}

// Index of the result under a client point, or -1
static int HitRow(int mx, int my) {
    const float s = (float)g_scale;
    float cx = 0, cy = 0;
    MainOrigin(cx, cy);
    const float cw = kWidth * s;
    const int rows = VisibleRows();
    if (rows <= 0) return -1;
    if (mx < cx || mx > cx + cw) return -1;

    const float rowsOrigin = RowsOriginPx(GetLay(cy, (float)g_curH * s));
    // The hit area is limited to what is really visible (rows area above the footer).
    const double hitH = std::min(ListRowsHeight(), ListViewportH());
    if (my < rowsOrigin || my >= rowsOrigin + (float)hitH * s) return -1;

    // With section headers the rows are not evenly spaced, so the row whose vertical range
    // contains the cursor is searched (headers are not selectable).
    const double scrollOff = ScrollPx();
    const int n = (int)g_results.size();
    const int first = std::max(0, (int)std::floor(g_scrollPos) - (g_kbScroll ? 2 : 0));
    const int last = std::min(n - 1, (int)std::ceil(g_scrollPos) + rows);
    for (int i = first; i <= last; ++i) {
        const float y0 = rowsOrigin + (float)(RowOffset((double)i) - scrollOff) * s;
        if (my >= y0 && my < y0 + kRowH * s) return i;
    }
    return -1;
}

// ===== Window =====

static bool RegisterLauncherHotkey() {
    UnregisterHotKey(g_hwnd, HOTKEY_ID);
    if (!RegisterHotKey(g_hwnd, HOTKEY_ID, g_cfg.hotkeyMods | MOD_NOREPEAT, g_cfg.hotkeyVk)) {
        return false;
    }
    return true;
}

static volatile LONG g_hotkeyWarnUp = 0;

static DWORD WINAPI HotkeyWarningThread(LPVOID) {
    MessageBoxW(nullptr,
                L"Spotlight Launcher could not register the keyboard shortcut because another "
                L"application is already using it (for example, Alt + Space is also the system "
                L"shortcut for a window's menu).\n\n"
                L"Change the shortcut in the mod settings or free that shortcut in the other "
                L"application.",
                L"Spotlight Launcher", MB_OK | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
    InterlockedExchange(&g_hotkeyWarnUp, 0);
    return 0;
}

static void RegisterHotkeyOrWarn() {
    if (!RegisterLauncherHotkey()) {
        Sleep(300);
        if (RegisterLauncherHotkey()) return;
        // User-triggered settings changes can call this repeatedly: keep a single warning visible
        // instead of stacking one box per change.
        if (InterlockedCompareExchange(&g_hotkeyWarnUp, 1, 0) == 0) {
            HANDLE th = CreateThread(nullptr, 0, HotkeyWarningThread, nullptr, 0, nullptr);
            if (th) CloseHandle(th);
        }
    }
}

namespace FluidShell {
void OnSettings();
}

static LRESULT CALLBACK LauncherWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_HOTKEY:
            if (wp == HOTKEY_ID) {
                // Respect the "Disable in fullscreen" toggle: while a fullscreen window is
                // focused, the shortcut does not open the search bar. Closing is still
                // allowed (it is already open, so the toggle only makes sense for opening).
                if (g_cfg.disableFullscreen && g_vis == Vis::Hidden && IsForegroundFullscreen()) {
                    return 0;
                }
                ToggleLauncher();
            }
            return 0;

        case WM_TIMER:
            if (wp == TIMER_FRAME) {
                OnFrame();
            } else if (wp == TIMER_CONFIRM) {
                KillTimer(g_hwnd, TIMER_CONFIRM);
                g_cmdArmed = -1;
                MarkDirty();
            } else if (wp == TIMER_COPY) {
                KillTimer(g_hwnd, TIMER_COPY);
                MarkDirty();  // redraw without the "Copied" flash
            } else if (wp == TIMER_CALC) {
                KillTimer(g_hwnd, TIMER_CALC);
                g_calcPending = false;
                g_calcHistSel = -1;
                g_histScroll = 0;
                UpdateCalc();
                RunSearch();
                UpdateTargets(false, /*followSelection=*/true);
                MarkDirty();
            } else if (wp == TIMER_BLINK) {
                if (g_vis == Vis::Shown && GetForegroundWindow() != g_hwnd &&
                    NowSec() - g_shownAt > 0.5) {
                    HideLauncher();  // focus was lost without WM_ACTIVATE arriving
                } else if (g_vis != Vis::Hidden) {
                    if (g_cfg.disableFullscreen && g_vis == Vis::Shown && IsForegroundFullscreen()) {
                        HideLauncher();
                    } else {
                        g_caretOn = !g_caretOn;
                        MarkDirty();
                    }
                }
            }
            return 0;

        case WM_ACTIVATE:
            if (LOWORD(wp) == WA_INACTIVE && g_vis != Vis::Hidden &&
                NowSec() - g_shownAt > 0.15) {
                HideLauncher();
            } else if (LOWORD(wp) == WA_ACTIVE && g_cfg.disableFullscreen &&
                       g_vis != Vis::Hidden && IsForegroundFullscreen()) {
                HideLauncher();
            }
            return 0;

        case WM_KEYDOWN:
            if (HandleKeyDown(wp)) return 0;
            break;

        case WM_CHAR: {
            wchar_t c = (wchar_t)wp;
            if (c == L' ' && CtrlDown()) return 0;  // Ctrl+Space (panel shortcut) does not type
            if (c >= 32 && c != 127) {
                ReplaceSelection(std::wstring(1, c));
                Sound::OnKey(c);
            }
            return 0;
        }

        // Alt held after the shortcut: do not open system menus or beep
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
        case WM_SYSCHAR:
            return 0;
        case WM_SYSCOMMAND:
            if ((wp & 0xFFF0) == SC_KEYMENU) return 0;
            break;

        case WM_MOUSEMOVE: {
            POINT p = {GET_X_LPARAM(lp), GET_Y_LPARAM(lp)};
            if (p.x != g_lastMouse.x || p.y != g_lastMouse.y) {
                bool first = g_lastMouse.x == -1 && g_lastMouse.y == -1;
                g_lastMouse = p;
                if (!first) {
                    if (CalcHistoryVisible()) {
                        const int h = HitCalcHistory(p.x, p.y);
                        if (h != g_calcHistSel) {
                            g_calcHistSel = h;
                            MarkDirty();
                        }
                    } else {
                        int row = HitRow(p.x, p.y);
                        if (row >= 0 && row != g_sel) {
                            // Hover selects, and the view scrolls to keep the selected row
                            // visible with one row of breathing room.
                            g_sel = row;
                            UpdateTargets(false, /*followSelection=*/true);
                            MarkDirty();
                        }
                    }
                }
            }
            const int act = HitAction(p.x, p.y);
            const bool overReindex = HitReindex(p.x, p.y);
            if (act != g_hoverAction || overReindex != g_hoverReindex) {
                g_hoverAction = act;
                g_hoverReindex = overReindex;
                MarkDirty();
            }
            return 0;
        }

        case WM_MOUSEWHEEL: {
            // The wheel scrolls the list; it does not change the selected app. The
            // selection stays where it is (or follows the mouse hover, which is handled in
            // WM_MOUSEMOVE).
            const int delta = GET_WHEEL_DELTA_WPARAM(wp);
            if (CalcHistoryVisible()) {
                const double step = (delta > 0 ? -3.0 : 3.0) * (double)kHistRowH;
                g_histScroll = std::max(0.0, g_histScroll + step);
                ClampHistScroll();
                MarkDirty();
                return 0;
            }
            const int rows = VisibleRows();
            const int n = (int)g_results.size();
            if (rows > 0 && n > 0) {
                const double step = (delta > 0 ? -3.0 : 3.0);
                double maxScroll = std::max(0, n - rows);
                g_kbScroll = false;  // wheel: back to row-based scroll
                g_scrollTarget = std::clamp(std::floor(g_scrollTarget + 0.5) + step, 0.0, maxScroll);
                MarkDirty();
            }
            return 0;
        }

        case WM_LBUTTONDOWN: {
            if (HitReindex(GET_X_LPARAM(lp), GET_Y_LPARAM(lp))) {
                ForceReindex();
                return 0;
            }
            int act = HitAction(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
            if (act >= 0) {
                RunActionOnSelection(act);
                return 0;
            }
            if (CalcHistoryVisible()) {
                const int h = HitCalcHistory(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
                if (h >= 0) {
                    InsertCalcHistory(h);
                }
                return 0;
            }
            int row = HitRow(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
            if (row >= 0) {
                g_sel = row;
                UpdateTargets(false, /*followSelection=*/true);
                LaunchSelected();
            }
            return 0;
        }

        case WM_MOUSEACTIVATE:
            return MA_ACTIVATE;

        case WM_ERASEBKGND:
            return 1;

        case WM_APP_INDEX: {
            auto* r = (IndexResult*)lp;
            if (r->gen == g_gen) ApplyIndex(*r);
            delete r;
            return 0;
        }
        case WM_APP_ICON: {
            auto* r = (IconResult*)lp;
            if (r->gen == g_gen && r->index < g_apps.size()) {
                AppEntry& a = g_apps[r->index];
                SafeRelease(a.bmp);
                a.iconW = r->w;
                a.iconH = r->h;
                a.iconPx = std::move(r->px);
                if (g_vis != Vis::Hidden) MarkDirty();
            }
            delete r;
            return 0;
        }
        case WM_APP_INDEX_DONE:
            if ((UINT)wp == g_gen) {
                g_indexing = false;
                g_indexedOnce = true;
                if (g_vis != Vis::Hidden) {
                    UpdateTargets(false, /*followSelection=*/true);
                    MarkDirty();
                }
                MaybeReindexInBackground();  // changes that arrived while indexing
            }
            return 0;

        case WM_APP_MENU_CHANGED:
            g_menuDirty = true;
            MaybeReindexInBackground();
            return 0;

        case WM_APP_SETTINGS: {
            const bool oldHideUtility = g_cfg.hideUtility;
            const bool oldScanDesktop = g_cfg.scanDesktop;
            LoadSettings();
            FluidShell::OnSettings();
            Sound::Configure();
            Sound::ApplyVolume();
            if (g_cfg.hideUtility != oldHideUtility || g_cfg.scanDesktop != oldScanDesktop) {
                g_menuDirty = true;  // the index must be rebuilt to apply this
            }
            RegisterHotkeyOrWarn();
            if (g_vis != Vis::Hidden) FinishHide();
            MaybeReindexInBackground();  // e.g. if switched to "Automatic" with pending changes
            return 0;
        }

        case WM_DESTROY:
            UnregisterHotKey(hwnd, HOTKEY_ID);
            return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

// ===== Fluid Shell: side bar (taskbar replacement) =====
namespace FluidShell {

struct Cfg {
    bool bar = true;
    bool left = true;
    int width = 56;
    int gap = 8;
    bool hideTaskbar = true;
    bool clock24 = true;
    bool flush = true;
    bool icons = false;
    int scalePct = 65;
    bool status = true;
    bool frame = true;
    int frameThick = 7;
    int windowGap = 8;
    int frameRadius = 10;
    bool dash = true;
    int dashKey = 0;  // 0 Ctrl+Alt+D, 1 Alt+Shift+D, 2 Win+Shift+D
    bool hotEdge = true;
    int hotEdgeMs = 250;
    std::wstring ignore;  // lowercase, separated by ; or ,
};
static Cfg cfg;

struct Item {
    HWND h = nullptr;
    std::wstring title;
    std::wstring name;  // short app name shown in the bar
    std::wstring stem;  // process name, e.g. "Code"
    int iw = 0, ih = 0;
    std::vector<uint32_t> px;
};

enum HitKind { H_START = 1, H_LAUNCHER, H_WINDOW, H_POWER, H_WIFI, H_VOLUME, H_BATTERY };
struct Hit {
    D2D1_RECT_F r;
    int kind;
    HWND h;
};

static const UINT WM_APPBAR_CB = WM_APP + 0x31;
static const UINT_PTR T_REFRESH = 101;
static const UINT_PTR T_TICK = 102;
static const UINT_PTR T_POS = 103;
static const UINT_PTR T_DASH = 104;   // dashboard animation
static const UINT_PTR T_EDGE = 105;   // hot edge polling / auto close
static const int HK_DASH = 78;
static const int HK_TASKBAR = 77;

static HWND sBar = nullptr;
static std::vector<Item> sItems;
static std::unordered_set<HWND> sIgnored;  // windows skipped because of the BarIgnore setting
static std::vector<Hit> sHits;
static int sHover = -1;
static bool sTracking = false;
static bool sRegistered = false;     // registered as an AppBar
static bool sHidden = false;         // the native taskbar is hidden by us
static bool sRevealed = false;       // the user pressed the restore hotkey
static bool sShellHooked = false;
static int sOrigState = -1;          // ABM_GETSTATE of the taskbar before we touched it
static RECT sRect = {};
static double sScale = 1.0;
static HDC sDC = nullptr;
static HBITMAP sDib = nullptr;
static HGDIOBJ sOldBmp = nullptr;
static int sW = 0, sH = 0;
static ID2D1DCRenderTarget* sRt = nullptr;
static ID2D1SolidColorBrush* sBr = nullptr;
static IDWriteTextFormat* sFmt = nullptr;
static IDWriteTextFormat* sFmtV = nullptr;        // rotated app name
static IDWriteInlineObject* sEllipsis = nullptr;
static std::wstring sActiveName;
static double sFmtScale = 0;
static UINT sHookMsg = 0, sCreatedMsg = 0;
static HWINEVENTHOOK sEvHook = nullptr;
static HWND sLastFg = nullptr;
static int sLastMinute = -1;
static int sTickCount = 0;
static HWND sDash = nullptr;          // dashboard window
static bool sDashWanted = false;      // open (or opening)
static double sDashK = 1.0;           // 1 = closed, 0 = fully open (spring state)
static double sDashV = 0.0;
static void DashApply();              // defined with the dashboard code further down
static void DashShutdown();
static bool sFsApp = false;       // Windows told us a fullscreen app is active (ABN_FULLSCREENAPP)
static bool sSuppressed = false;  // the bar is hidden because of a fullscreen app

static void LoadCfg() {
    Cfg n;
    n.bar = Wh_GetIntSetting(L"BarEnabled") != 0;
    n.left = GetStringSetting(L"BarSide") != L"right";
    n.width = std::clamp(Wh_GetIntSetting(L"BarWidth"), 36, 120);
    n.gap = std::clamp(Wh_GetIntSetting(L"BarGap"), 0, 60);
    n.hideTaskbar = Wh_GetIntSetting(L"HideNativeTaskbar") != 0;
    n.clock24 = Wh_GetIntSetting(L"BarClock24h") != 0;
    n.flush = Wh_GetIntSetting(L"BarFlushToEdge") != 0;
    n.icons = Wh_GetIntSetting(L"BarShowIcons") != 0;
    {
        int bs = Wh_GetIntSetting(L"BarScale");
        if (bs <= 0) bs = 65;  // setting not present yet
        n.scalePct = std::clamp(bs, 40, 150);
    }
    n.status = Wh_GetIntSetting(L"BarShowStatus") != 0;
    n.frame = Wh_GetIntSetting(L"FrameEnabled") != 0;
    {
        int ft = Wh_GetIntSetting(L"FrameThickness");
        if (ft <= 0) ft = 7;
        n.frameThick = std::clamp(ft, 2, 40);
        int wg = Wh_GetIntSetting(L"WindowGap");
        if (wg < 0) wg = 8;
        n.windowGap = std::clamp(wg, 0, 60);
        int fr = Wh_GetIntSetting(L"FrameCornerRadius");
        if (fr <= 0) fr = 10;
        n.frameRadius = std::clamp(fr, 2, 36);
        n.dash = Wh_GetIntSetting(L"DashboardEnabled") != 0;
        {
            const std::wstring dk = GetStringSetting(L"DashboardHotkey");
            n.dashKey = (dk == L"altshiftd") ? 1 : (dk == L"winshiftd") ? 2 : 0;
        }
        n.hotEdge = Wh_GetIntSetting(L"DashboardHotEdge") != 0;
        int hm = Wh_GetIntSetting(L"HotEdgeDelay");
        if (hm <= 0) hm = 250;
        n.hotEdgeMs = std::clamp(hm, 50, 2000);
    }
    n.ignore = LowerAscii(GetStringSetting(L"BarIgnore"));
    cfg = n;
}

// ---------------------------------------------------------------- open windows
static bool WantWindow(HWND h) {
    if (h == sBar || h == g_hwnd || h == g_liveWnd || h == g_livePanel) return false;
    if (!IsWindowVisible(h) || GetWindow(h, GW_OWNER)) return false;
    const LONG_PTR ex = GetWindowLongPtrW(h, GWL_EXSTYLE);
    if ((ex & WS_EX_TOOLWINDOW) && !(ex & WS_EX_APPWINDOW)) return false;
    if (IsWindowCloaked(h)) return false;
    if ((ex & WS_EX_NOACTIVATE) && !(ex & WS_EX_APPWINDOW)) return false;  // overlays, popups
    if (!IsIconic(h)) {  // tiny windows are helpers of background apps
        RECT wr = {};
        if (!GetWindowRect(h, &wr) || wr.right - wr.left < 80 || wr.bottom - wr.top < 40) return false;
    }
    wchar_t title[8] = {};
    if (GetWindowTextW(h, title, ARRAYSIZE(title)) <= 0) return false;
    wchar_t cls[64] = {};
    GetClassNameW(h, cls, ARRAYSIZE(cls));
    if (lstrcmpW(cls, L"Progman") == 0 || lstrcmpW(cls, L"Windows.UI.Core.CoreWindow") == 0) return false;
    return true;
}

static void FetchIcon(HWND h, Item& it) {
    {
        // Windows of a Windhawk install (its editor is VSCodium) get the Windhawk icon.
        DWORD wpid = 0;
        GetWindowThreadProcessId(h, &wpid);
        const std::wstring wpath = ProcessImagePath(wpid);
        {
            const size_t sl = wpath.find_last_of(L"\\/");
            std::wstring st = (sl == std::wstring::npos) ? wpath : wpath.substr(sl + 1);
            if (st.size() > 4 && LowerAscii(st.substr(st.size() - 4)) == L".exe") st.resize(st.size() - 4);
            if (!st.empty()) st[0] = (wchar_t)towupper(st[0]);
            it.stem = st;
        }
        const size_t k = LowerAscii(wpath).find(L"\\windhawk\\");
        if (k != std::wstring::npos) {
            Pix wp;
            if (GetFileIconPix(wpath.substr(0, k + 10) + L"windhawk.exe", wp) && HasVisiblePixels(wp)) {
                it.iw = wp.w;
                it.ih = wp.h;
                it.px = std::move(wp.px);
                return;
            }
        }
    }
    HICON hi = nullptr;
    DWORD_PTR res = 0;
    if (SendMessageTimeoutW(h, WM_GETICON, ICON_BIG, 0, SMTO_ABORTIFHUNG, 40, &res) && res) hi = (HICON)res;
    if (!hi && SendMessageTimeoutW(h, WM_GETICON, ICON_SMALL2, 0, SMTO_ABORTIFHUNG, 40, &res) && res) {
        hi = (HICON)res;
    }
    if (!hi) hi = (HICON)GetClassLongPtrW(h, GCLP_HICON);
    Pix p;
    bool ok = hi && HIconToPix(hi, p) && HasVisiblePixels(p);
    if (!ok) {
        DWORD pid = 0;
        GetWindowThreadProcessId(h, &pid);
        const std::wstring path = ProcessImagePath(pid);
        if (!path.empty()) {
            p = Pix();
            ok = GetFileIconPix(path, p) && HasVisiblePixels(p);
        }
    }
    if (ok) {
        it.iw = p.w;
        it.ih = p.h;
        it.px = std::move(p.px);
    }
}

static BOOL CALLBACK EnumProc(HWND h, LPARAM lp) {
    if (WantWindow(h)) ((std::vector<HWND>*)lp)->push_back(h);
    return TRUE;
}

// "file.cpp - project - Visual Studio Code" -> "Visual Studio Code"; long titles fall back to the process name.
static std::wstring AppName(const Item& it) {
    const std::wstring& t = it.title;
    static const wchar_t* const kSeps[] = {L" - ", L" \u2013 ", L" \u2014 ", L" | "};
    size_t best = std::wstring::npos, len = 0;
    for (const wchar_t* sp : kSeps) {
        const size_t p = t.rfind(sp);
        if (p != std::wstring::npos && (best == std::wstring::npos || p > best)) {
            best = p;
            len = wcslen(sp);
        }
    }
    std::wstring n = (best != std::wstring::npos) ? t.substr(best + len) : t;
    while (!n.empty() && n.front() == L' ') n.erase(n.begin());
    while (!n.empty() && n.back() == L' ') n.pop_back();
    if ((n.empty() || n.size() > 28) && !it.stem.empty()) n = it.stem;
    if (n.empty()) n = L"App";
    return n;
}

static bool IsUserIgnored(HWND h) {
    if (cfg.ignore.empty()) return false;
    DWORD pid = 0;
    GetWindowThreadProcessId(h, &pid);
    const std::wstring path = LowerAscii(ProcessImagePath(pid));
    const size_t sl = path.find_last_of(L"\\/");
    const std::wstring stem = (sl == std::wstring::npos) ? path : path.substr(sl + 1);
    wchar_t t[160] = {};
    GetWindowTextW(h, t, ARRAYSIZE(t));
    const std::wstring title = LowerAscii(t);
    size_t p = 0;
    while (p <= cfg.ignore.size()) {
        size_t e = cfg.ignore.find_first_of(L";,", p);
        if (e == std::wstring::npos) e = cfg.ignore.size();
        std::wstring tok = cfg.ignore.substr(p, e - p);
        while (!tok.empty() && tok.front() == L' ') tok.erase(tok.begin());
        while (!tok.empty() && tok.back() == L' ') tok.pop_back();
        if (!tok.empty() && (stem.find(tok) != std::wstring::npos || title.find(tok) != std::wstring::npos)) {
            return true;
        }
        p = e + 1;
    }
    return false;
}

// Keeps a stable order (new windows are appended) and only fetches icons for new windows.
static void RefreshItems() {
    std::vector<HWND> now;
    EnumWindows(EnumProc, (LPARAM)&now);
    std::vector<Item> next;
    for (Item& it : sItems) {
        if (std::find(now.begin(), now.end(), it.h) != now.end()) next.push_back(std::move(it));
    }
    for (auto it = sIgnored.begin(); it != sIgnored.end();) {
        if (std::find(now.begin(), now.end(), *it) == now.end()) {
            it = sIgnored.erase(it);
        } else {
            ++it;
        }
    }
    for (auto r = now.rbegin(); r != now.rend(); ++r) {
        if (sIgnored.count(*r)) continue;
        bool have = false;
        for (const Item& x : next) {
            if (x.h == *r) {
                have = true;
                break;
            }
        }
        if (!have) {
            if (IsUserIgnored(*r)) {
                sIgnored.insert(*r);
                continue;
            }
            Item n;
            n.h = *r;
            FetchIcon(*r, n);
            next.push_back(std::move(n));
        }
    }
    for (Item& it : next) {
        wchar_t t[160] = {};
        GetWindowTextW(it.h, t, ARRAYSIZE(t));
        it.title = t;
        it.name = AppName(it);
    }
    sItems.swap(next);
}

// ---------------------------------------------------------------- native taskbar
static BOOL CALLBACK EnumSecondaryTrays(HWND h, LPARAM lp) {
    wchar_t cls[64] = {};
    GetClassNameW(h, cls, ARRAYSIZE(cls));
    if (lstrcmpW(cls, L"Shell_SecondaryTrayWnd") == 0) ((std::vector<HWND>*)lp)->push_back(h);
    return TRUE;
}

static void ShowTrays(bool show) {
    std::vector<HWND> trays;
    if (HWND t = FindWindowW(L"Shell_TrayWnd", nullptr)) trays.push_back(t);
    EnumWindows(EnumSecondaryTrays, (LPARAM)&trays);
    for (HWND t : trays) ShowWindow(t, show ? SW_SHOWNA : SW_HIDE);
}

static void SetTaskbarHidden(bool hide) {
    HWND tray = FindWindowW(L"Shell_TrayWnd", nullptr);
    if (!tray) return;
    APPBARDATA abd = {};
    abd.cbSize = sizeof(abd);
    abd.hWnd = tray;
    if (hide) {
        if (sOrigState < 0) sOrigState = (int)SHAppBarMessage(ABM_GETSTATE, &abd);
        abd.lParam = ABS_AUTOHIDE | (sOrigState & ABS_ALWAYSONTOP);
        SHAppBarMessage(ABM_SETSTATE, &abd);
        ShowTrays(false);
        sHidden = true;
    } else if (sHidden) {
        abd.lParam = sOrigState >= 0 ? (LPARAM)sOrigState : (LPARAM)ABS_ALWAYSONTOP;
        SHAppBarMessage(ABM_SETSTATE, &abd);
        ShowTrays(true);
        sHidden = false;
    }
}

// Explorer shows the taskbar again in several situations: push it back while we own it.
static void CALLBACK WinEventProc(HWINEVENTHOOK, DWORD, HWND h, LONG idObject, LONG, DWORD, DWORD) {
    if (!sHidden || idObject != OBJID_WINDOW || !h) return;
    wchar_t cls[64] = {};
    GetClassNameW(h, cls, ARRAYSIZE(cls));
    if (lstrcmpW(cls, L"Shell_TrayWnd") == 0 || lstrcmpW(cls, L"Shell_SecondaryTrayWnd") == 0) {
        if (IsWindowVisible(h)) ShowWindow(h, SW_HIDE);
    }
}

static void InstallEvHook() {
    if (!sEvHook) {
        sEvHook = SetWinEventHook(EVENT_OBJECT_SHOW, EVENT_OBJECT_SHOW, nullptr, WinEventProc, 0, 0,
                                  WINEVENT_OUTOFCONTEXT);
    }
}

static void RemoveEvHook() {
    if (sEvHook) {
        UnhookWinEvent(sEvHook);
        sEvHook = nullptr;
    }
}

static void HookShell() {
    if (sShellHooked || !sBar) return;
    typedef BOOL(WINAPI * Fn)(HWND);
    HMODULE u = GetModuleHandleW(L"user32.dll");
    auto fn = u ? (Fn)GetProcAddress(u, "RegisterShellHookWindow") : nullptr;
    if (fn && fn(sBar)) sShellHooked = true;
}

static void UnhookShell() {
    if (!sShellHooked || !sBar) return;
    typedef BOOL(WINAPI * Fn)(HWND);
    HMODULE u = GetModuleHandleW(L"user32.dll");
    auto fn = u ? (Fn)GetProcAddress(u, "DeregisterShellHookWindow") : nullptr;
    if (fn) fn(sBar);
    sShellHooked = false;
}

// ---------------------------------------------------------------- surface
static bool EnsureSurface(int w, int h) {
    if (sDib && w == sW && h == sH) return true;
    if (!sDC) sDC = CreateCompatibleDC(nullptr);
    if (sDib) {
        SelectObject(sDC, sOldBmp);
        DeleteObject(sDib);
        sDib = nullptr;
    }
    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = w;
    bi.bmiHeader.biHeight = -h;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    sDib = CreateDIBSection(nullptr, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (!sDib) return false;
    sOldBmp = SelectObject(sDC, sDib);
    sW = w;
    sH = h;
    return true;
}

static bool EnsureRt() {
    if (sRt && sBr) return true;
    SafeRelease(sBr);
    SafeRelease(sRt);
    if (!g_d2d) return false;
    D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_DEFAULT,
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED), 96.f, 96.f,
        D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT);
    if (FAILED(g_d2d->CreateDCRenderTarget(&props, &sRt)) || !sRt) return false;
    sRt->SetDpi(96.f, 96.f);
    sRt->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 1), &sBr);
    return sBr != nullptr;
}

// Name of the app that has the focus; "Desktop" when nothing but the desktop / taskbar is focused.
// When another window of ours (the launcher) has the focus the last name stays.
static void UpdateActiveName(HWND fg) {
    for (const Item& it : sItems) {
        if (it.h == fg) {
            sActiveName = it.name;
            return;
        }
    }
    wchar_t cls[64] = {};
    if (fg && GetClassNameW(fg, cls, ARRAYSIZE(cls)) &&
        (lstrcmpW(cls, L"Progman") == 0 || lstrcmpW(cls, L"WorkerW") == 0 ||
         lstrcmpW(cls, L"Shell_TrayWnd") == 0)) {
        sActiveName = L"Desktop";
    } else if (sActiveName.empty()) {
        sActiveName = L"Desktop";
    }
}

// True when the foreground window covers the whole monitor (fullscreen video, F11 browser, games).
// Unlike the launcher's check this does not ignore maximized-state windows: with the AppBar reserved a
// normal maximized window never reaches the screen edge, so a window that does is fullscreen.
static bool ForegroundCoversMonitor() {
    HWND fg = GetForegroundWindow();
    if (!fg || fg == sBar || fg == g_hwnd) return false;
    DWORD fgPid = 0;
    GetWindowThreadProcessId(fg, &fgPid);
    if (fgPid == GetCurrentProcessId()) return false;  // never react to our own windows
    wchar_t cls[64] = {};
    if (GetClassNameW(fg, cls, ARRAYSIZE(cls))) {
        if (lstrcmpW(cls, L"Progman") == 0 || lstrcmpW(cls, L"WorkerW") == 0 ||
            lstrcmpW(cls, L"Shell_TrayWnd") == 0 || lstrcmpW(cls, L"Shell_SecondaryTrayWnd") == 0 ||
            lstrcmpW(cls, L"Windows.UI.Core.CoreWindow") == 0 ||
            lstrcmpW(cls, L"XamlExplorerHostIslandWindow") == 0) {
            return false;
        }
    }
    RECT wr = {};
    if (!GetWindowRect(fg, &wr)) return false;
    MONITORINFO mi = {};
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfoW(MonitorFromWindow(fg, MONITOR_DEFAULTTONEAREST), &mi)) return false;
    const RECT& m = mi.rcMonitor;
    const int tol = 2;
    return wr.left <= m.left + tol && wr.top <= m.top + tol && wr.right >= m.right - tol &&
           wr.bottom >= m.bottom - tol;
}

// ===== Status data: volume, battery, network =====
struct Status {
    bool hasVolume = false;
    float volume = 0.f;
    bool muted = false;
    bool hasBattery = false;
    int batPct = 0;
    bool charging = false;
    bool ac = false;
    bool netAvail = false;  // the network icon is shown once the first poll ran
    int net = 0;            // 0 = none, 1 = Wi-Fi, 2 = wired / other
    int wifiQuality = 0;    // 0..100
    std::wstring ssid;
};
static Status sSt;
static IAudioEndpointVolume* sEpVol = nullptr;

static void ReleaseVolume() {
    if (sEpVol) {
        sEpVol->Release();
        sEpVol = nullptr;
    }
}

static bool AcquireVolume() {
    ReleaseVolume();
    IMMDeviceEnumerator* en = nullptr;
    if (FAILED(CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&en))) || !en) {
        return false;
    }
    bool ok = false;
    IMMDevice* dev = nullptr;
    if (SUCCEEDED(en->GetDefaultAudioEndpoint(eRender, eMultimedia, &dev)) && dev) {
        ok = SUCCEEDED(dev->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, nullptr, (void**)&sEpVol)) && sEpVol;
        dev->Release();
    }
    en->Release();
    return ok;
}

static bool PollVolume() {
    if (!sEpVol && !AcquireVolume()) {
        const bool changed = sSt.hasVolume;
        sSt.hasVolume = false;
        return changed;
    }
    float lv = 0.f;
    BOOL mute = FALSE;
    if (FAILED(sEpVol->GetMasterVolumeLevelScalar(&lv)) || FAILED(sEpVol->GetMute(&mute))) {
        ReleaseVolume();  // the default device changed: look it up again next time
        return false;
    }
    const bool m = mute != FALSE;
    const bool changed = !sSt.hasVolume || std::fabs(lv - sSt.volume) > 0.004f || m != sSt.muted;
    sSt.hasVolume = true;
    sSt.volume = lv;
    sSt.muted = m;
    return changed;
}

static bool PollBattery() {
    SYSTEM_POWER_STATUS p = {};
    const bool ok = GetSystemPowerStatus(&p) != 0;
    const bool has = ok && p.BatteryFlag != 255 && !(p.BatteryFlag & 128);
    const int pct = (has && p.BatteryLifePercent <= 100) ? (int)p.BatteryLifePercent : 0;
    const bool chg = has && (p.BatteryFlag & 8) != 0;
    const bool ac = ok && p.ACLineStatus == 1;
    const bool changed = has != sSt.hasBattery || pct != sSt.batPct || chg != sSt.charging || ac != sSt.ac;
    sSt.hasBattery = has;
    sSt.batPct = pct;
    sSt.charging = chg;
    sSt.ac = ac;
    return changed;
}

// Wi-Fi through the WLAN API, loaded dynamically with local copies of the few structures we read.
struct WlanIfInfo {
    GUID guid;
    WCHAR desc[256];
    int state;  // 1 = connected
};
struct WlanIfList {
    DWORD num;
    DWORD idx;
    WlanIfInfo info[1];
};
struct WlanAssoc {
    ULONG ssidLen;
    UCHAR ssid[32];
    int bssType;
    UCHAR bssid[6];
    int phyType;
    ULONG phyIndex;
    ULONG quality;
    ULONG rxRate;
    ULONG txRate;
};
struct WlanConn {
    int state;
    int mode;
    WCHAR profile[256];
    WlanAssoc assoc;
};
typedef DWORD(WINAPI* PWlanOpen)(DWORD, PVOID, PDWORD, PHANDLE);
typedef DWORD(WINAPI* PWlanClose)(HANDLE, PVOID);
typedef DWORD(WINAPI* PWlanEnum)(HANDLE, PVOID, WlanIfList**);
typedef DWORD(WINAPI* PWlanQuery)(HANDLE, const GUID*, int, PVOID, PDWORD, PVOID*, PVOID);
typedef VOID(WINAPI* PWlanFree)(PVOID);

static bool QueryWifi(int& quality, std::wstring& ssid) {
    static bool tried = false;
    static PWlanOpen pOpen = nullptr;
    static PWlanClose pClose = nullptr;
    static PWlanEnum pEnum = nullptr;
    static PWlanQuery pQuery = nullptr;
    static PWlanFree pFree = nullptr;
    if (!tried) {
        tried = true;
        HMODULE m = LoadLibraryExW(L"wlanapi.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
        if (m) {
            pOpen = (PWlanOpen)GetProcAddress(m, "WlanOpenHandle");
            pClose = (PWlanClose)GetProcAddress(m, "WlanCloseHandle");
            pEnum = (PWlanEnum)GetProcAddress(m, "WlanEnumInterfaces");
            pQuery = (PWlanQuery)GetProcAddress(m, "WlanQueryInterface");
            pFree = (PWlanFree)GetProcAddress(m, "WlanFreeMemory");
        }
    }
    if (!pOpen || !pClose || !pEnum || !pQuery || !pFree) return false;

    HANDLE h = nullptr;
    DWORD ver = 0;
    if (pOpen(2, nullptr, &ver, &h) != ERROR_SUCCESS || !h) return false;
    bool found = false;
    WlanIfList* list = nullptr;
    if (pEnum(h, nullptr, &list) == ERROR_SUCCESS && list) {
        for (DWORD i = 0; i < list->num && !found; ++i) {
            const WlanIfInfo& ii = list->info[i];
            if (ii.state != 1) continue;
            WlanConn* conn = nullptr;
            DWORD sz = 0;
            if (pQuery(h, &ii.guid, 7 /*wlan_intf_opcode_current_connection*/, nullptr, &sz, (PVOID*)&conn,
                       nullptr) == ERROR_SUCCESS &&
                conn) {
                quality = (int)conn->assoc.quality;
                ssid.clear();
                if (conn->assoc.ssidLen > 0 && conn->assoc.ssidLen <= 32) {
                    wchar_t wb[64] = {};
                    const int n = MultiByteToWideChar(CP_UTF8, 0, (LPCCH)conn->assoc.ssid, (int)conn->assoc.ssidLen,
                                                      wb, 63);
                    if (n > 0) ssid.assign(wb, n);
                }
                found = true;
                pFree(conn);
            }
        }
        pFree(list);
    }
    pClose(h, nullptr);
    return found;
}

typedef BOOL(WINAPI* PInetConnected)(LPDWORD, DWORD);
static bool AnyConnection() {
    static bool tried = false;
    static PInetConnected fn = nullptr;
    if (!tried) {
        tried = true;
        HMODULE m = LoadLibraryExW(L"wininet.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
        if (m) fn = (PInetConnected)GetProcAddress(m, "InternetGetConnectedState");
    }
    DWORD flags = 0;
    return fn && fn(&flags, 0) != FALSE;
}

// The WLAN / connectivity calls can block for a while, so they run in their own thread; the UI thread
// only copies the last snapshot.
struct NetSnap {
    int net = 0;
    int q = 0;
    std::wstring ssid;
    bool valid = false;
};
static NetSnap sNetShared;
static CRITICAL_SECTION sNetCs;
static bool sNetCsInit = false;
static HANDLE sNetThread = nullptr;
static HANDLE sNetStop = nullptr;

static DWORD WINAPI NetThreadProc(LPVOID) {
    for (;;) {
        NetSnap n;
        if (QueryWifi(n.q, n.ssid)) {
            n.net = 1;
        } else if (AnyConnection()) {
            n.net = 2;
        }
        n.valid = true;
        EnterCriticalSection(&sNetCs);
        sNetShared = n;
        LeaveCriticalSection(&sNetCs);
        if (WaitForSingleObject(sNetStop, 5000) == WAIT_OBJECT_0) break;
    }
    return 0;
}

static void StartNetThread() {
    if (sNetThread) return;
    if (!sNetCsInit) {
        InitializeCriticalSection(&sNetCs);
        sNetCsInit = true;
    }
    sNetStop = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    if (!sNetStop) return;
    sNetThread = CreateThread(nullptr, 0, NetThreadProc, nullptr, 0, nullptr);
    if (!sNetThread) {
        CloseHandle(sNetStop);
        sNetStop = nullptr;
    }
}

static void StopNetThread() {
    if (!sNetThread) return;
    SetEvent(sNetStop);
    WaitForSingleObject(sNetThread, 3000);
    CloseHandle(sNetThread);
    CloseHandle(sNetStop);
    sNetThread = nullptr;
    sNetStop = nullptr;
}

static bool PollNet() {
    if (!sNetCsInit) return false;
    NetSnap snap;
    EnterCriticalSection(&sNetCs);
    snap = sNetShared;
    LeaveCriticalSection(&sNetCs);
    if (!snap.valid) return false;
    const bool changed = !sSt.netAvail || snap.net != sSt.net ||
                         (snap.net == 1 && (snap.q / 10 != sSt.wifiQuality / 10 || snap.ssid != sSt.ssid));
    sSt.netAvail = true;
    sSt.net = snap.net;
    sSt.wifiQuality = snap.q;
    sSt.ssid = snap.ssid;
    return changed;
}

// Volume is polled on every tick; battery and network only when `full` (every ~5 s).
static bool PollStatus(bool full) {
    bool ch = false;
    static int n = 0;
    if (full && ++n % 2 == 0) ReleaseVolume();  // pick up a changed default device every ~10 s
    if (PollVolume()) ch = true;
    if (full) {
        if (PollBattery()) ch = true;
        if (PollNet()) ch = true;
    }
    return ch;
}

static std::wstring StatusLabel(int kind) {
    wchar_t b[128] = {};
    if (kind == H_VOLUME) {
        if (sSt.muted) return L"Muted";
        swprintf_s(b, L"Volume %d%%", (int)std::lround(sSt.volume * 100.f));
        return b;
    }
    if (kind == H_BATTERY) {
        swprintf_s(b, L"Battery %d%%%ls", sSt.batPct,
                   sSt.charging ? L" - charging" : (sSt.ac ? L" - plugged in" : L""));
        return b;
    }
    if (kind == H_WIFI) {
        if (sSt.net == 1) return L"Wi-Fi: " + (sSt.ssid.empty() ? std::wstring(L"connected") : sSt.ssid);
        if (sSt.net == 2) return L"Network connected";
        return L"No network";
    }
    return L"";
}

// ===== Screen frame: three AppBar strips + four corner pieces =====
// No window covers the whole screen. The strips sit on the edges the bar does not use (they never overlap
// the bar), the corner pieces draw the rounded inner corners. Everything is click-through.
static HWND sEdge[3] = {};
static bool sEdgeReg[3] = {false, false, false};
static RECT sEdgeRect[3] = {};
static HWND sCorner[4] = {};
static HINSTANCE sInstH = nullptr;
static double sDpi = 1.0;
static ULONGLONG sAbnIgnoreUntil = 0;  // AppBar notifications caused by our own placement are ignored
static RECT sInner = {};               // the area inside the frame / bar (screen coordinates)
static RECT sMonRect = {};
static bool sInnerValid = false;
static std::wstring sFrameSig;         // what is currently painted

static LRESULT CALLBACK OverlayProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    if (m == WM_MOUSEACTIVATE) return MA_NOACTIVATE;
    return DefWindowProcW(h, m, w, l);
}

static HWND MakeOverlayWindow(const wchar_t* title) {
    static bool registered = false;
    if (!registered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = OverlayProc;
        wc.hInstance = sInstH;
        wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
        wc.lpszClassName = L"FluidShellOverlay";
        RegisterClassExW(&wc);
        registered = true;
    }
    return CreateWindowExW(WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_NOACTIVATE,
                           L"FluidShellOverlay", title, WS_POPUP, 0, 0, 10, 10, nullptr, nullptr, sInstH, nullptr);
}

static uint32_t PackPremul(const D2D1_COLOR_F& c, float a) {
    a = std::clamp(a, 0.f, 1.f);
    const uint32_t A = (uint32_t)std::lround(a * 255.f);
    const uint32_t R = (uint32_t)std::lround(std::clamp(c.r, 0.f, 1.f) * 255.f * a);
    const uint32_t G = (uint32_t)std::lround(std::clamp(c.g, 0.f, 1.f) * 255.f * a);
    const uint32_t B = (uint32_t)std::lround(std::clamp(c.b, 0.f, 1.f) * 255.f * a);
    return (A << 24) | (R << 16) | (G << 8) | B;
}

static void PaintLayered(HWND h, int w, int ht, const std::vector<uint32_t>& px) {
    if (!h || w <= 0 || ht <= 0 || px.size() < (size_t)w * (size_t)ht) return;
    HDC dc = CreateCompatibleDC(nullptr);
    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = w;
    bi.bmiHeader.biHeight = -ht;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    HBITMAP dib = CreateDIBSection(nullptr, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (dib && bits && dc) {
        memcpy(bits, px.data(), (size_t)w * (size_t)ht * 4);
        HGDIOBJ old = SelectObject(dc, dib);
        SIZE sz = {w, ht};
        POINT src = {0, 0};
        BLENDFUNCTION bf = {};
        bf.BlendOp = AC_SRC_OVER;
        bf.SourceConstantAlpha = 255;
        bf.AlphaFormat = AC_SRC_ALPHA;
        UpdateLayeredWindow(h, nullptr, nullptr, &sz, dc, &src, 0, &bf, ULW_ALPHA);
        SelectObject(dc, old);
    }
    if (dib) DeleteObject(dib);
    if (dc) DeleteDC(dc);
}

static void PaintSolid(HWND h, int w, int ht, const D2D1_COLOR_F& c) {
    if (w <= 0 || ht <= 0) return;
    std::vector<uint32_t> px((size_t)w * (size_t)ht, PackPremul(c, 1.f));
    PaintLayered(h, w, ht, px);
}

// corner: 0 = top-left, 1 = top-right, 2 = bottom-left, 3 = bottom-right of the inner area.
// The piece fills the part of the R x R square that lies OUTSIDE the quarter circle (anti-aliased).
static void PaintCorner(HWND h, int R, int corner, const D2D1_COLOR_F& c) {
    if (R < 1) return;
    std::vector<uint32_t> px((size_t)R * (size_t)R);
    const float ccx = (corner == 0 || corner == 2) ? (float)R : 0.f;
    const float ccy = (corner == 0 || corner == 1) ? (float)R : 0.f;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < R; ++x) {
            const float dx = x + 0.5f - ccx, dy = y + 0.5f - ccy;
            const float d = std::sqrt(dx * dx + dy * dy);
            px[(size_t)y * (size_t)R + (size_t)x] = PackPremul(c, std::clamp(d - (float)R + 0.5f, 0.f, 1.f));
        }
    }
    PaintLayered(h, R, R, px);
}

static void PlaceStrip(int i, UINT edge, RECT rc, RECT reserve, const D2D1_COLOR_F& col) {
    if (!sEdge[i]) {
        sEdge[i] = MakeOverlayWindow(L"Fluid Shell Edge");
        if (!sEdge[i]) return;
    }
    APPBARDATA abd = {};
    abd.cbSize = sizeof(abd);
    abd.hWnd = sEdge[i];
    if (!sEdgeReg[i] && SHAppBarMessage(ABM_NEW, &abd)) {
        sEdgeReg[i] = true;
        sAbnIgnoreUntil = GetTickCount64() + 800;
    }
    if (!EqualRect(&sEdgeRect[i], &reserve)) {
        abd.uEdge = edge;
        abd.rc = reserve;  // reserved space = visible strip + the gap for maximized windows
        SHAppBarMessage(ABM_QUERYPOS, &abd);
        abd.rc = reserve;
        SHAppBarMessage(ABM_SETPOS, &abd);
        sEdgeRect[i] = reserve;
        sAbnIgnoreUntil = GetTickCount64() + 800;
    }
    // The window itself only covers the visible strip.
    SetWindowPos(sEdge[i], HWND_TOPMOST, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top,
                 SWP_NOACTIVATE | (sSuppressed ? 0 : SWP_SHOWWINDOW));
    PaintSolid(sEdge[i], rc.right - rc.left, rc.bottom - rc.top, col);
}

static void TeardownFrame() {
    for (int i = 0; i < 3; ++i) {
        if (!sEdge[i]) continue;
        if (sEdgeReg[i]) {
            APPBARDATA abd = {};
            abd.cbSize = sizeof(abd);
            abd.hWnd = sEdge[i];
            SHAppBarMessage(ABM_REMOVE, &abd);
            sEdgeReg[i] = false;
        }
        DestroyWindow(sEdge[i]);
        sEdge[i] = nullptr;
        sEdgeRect[i] = RECT{};
    }
    for (int i = 0; i < 4; ++i) {
        if (sCorner[i]) {
            DestroyWindow(sCorner[i]);
            sCorner[i] = nullptr;
        }
    }
    sFrameSig.clear();
}

static void PositionFrame(const RECT& mon) {
    if (!cfg.bar || !cfg.frame) {
        TeardownFrame();
        return;
    }
    sDpi = MonitorScale(MonitorFromPoint(POINT{0, 0}, MONITOR_DEFAULTTOPRIMARY));
    const int T = (int)std::lround(cfg.frameThick * sDpi);
    const int bw = (int)std::lround(cfg.width * sScale);
    const int W = mon.right - mon.left, H = mon.bottom - mon.top;
    const int il = cfg.left ? bw : T;   // inner area: left inset
    const int ir = cfg.left ? T : bw;   // inner area: right inset
    int R = (int)std::lround(cfg.frameRadius * sDpi);
    R = std::clamp(R, 0, std::max(0, std::min(W - il - ir, H - 2 * T) / 2));

    D2D1_COLOR_F col = g_pal.bg;
    col.a = 1.f;  // same opaque colour as the bar so they read as one piece
    wchar_t sb[256] = {};
    swprintf_s(sb, L"%d,%d,%d,%d,%d,%d,%d,%d,%d,%.3f,%.3f,%.3f", (int)mon.left, (int)mon.top, W, H, T, bw, R,
               cfg.left ? 1 : 0, cfg.windowGap, col.r, col.g, col.b);
    const std::wstring sig = sb;
    if (sig == sFrameSig && sEdge[0] && sEdge[1] && sEdge[2]) return;  // nothing changed: do not touch anything

    // Strips on the three edges the bar does not use. Top / bottom stop at the bar, the side strip stops at
    // the top / bottom strips, so nothing overlaps.
    const int G = (int)std::lround(cfg.windowGap * sDpi);
    const int x0 = cfg.left ? mon.left + bw - 1 : mon.left;      // 1 px under the bar: no hairline between them
    const int x1 = cfg.left ? mon.right : mon.right - bw + 1;
    PlaceStrip(0, ABE_TOP, RECT{x0, mon.top, x1, mon.top + T},
               RECT{mon.left, mon.top, mon.right, mon.top + T + G}, col);
    PlaceStrip(1, ABE_BOTTOM, RECT{x0, mon.bottom - T, x1, mon.bottom},
               RECT{mon.left, mon.bottom - T - G, mon.right, mon.bottom}, col);
    if (cfg.left) {
        PlaceStrip(2, ABE_RIGHT, RECT{mon.right - T, mon.top + T - 1, mon.right, mon.bottom - T + 1},
                   RECT{mon.right - T - G, mon.top, mon.right, mon.bottom}, col);
    } else {
        PlaceStrip(2, ABE_LEFT, RECT{mon.left, mon.top + T - 1, mon.left + T, mon.bottom - T + 1},
                   RECT{mon.left, mon.top, mon.left + T + G, mon.bottom}, col);
    }

    // Rounded inner corners
    const RECT cr[4] = {
        {mon.left + il, mon.top + T, mon.left + il + R, mon.top + T + R},
        {mon.right - ir - R, mon.top + T, mon.right - ir, mon.top + T + R},
        {mon.left + il, mon.bottom - T - R, mon.left + il + R, mon.bottom - T},
        {mon.right - ir - R, mon.bottom - T - R, mon.right - ir, mon.bottom - T},
    };
    for (int i = 0; i < 4; ++i) {
        if (R < 2) {
            if (sCorner[i]) ShowWindow(sCorner[i], SW_HIDE);
            continue;
        }
        if (!sCorner[i]) sCorner[i] = MakeOverlayWindow(L"Fluid Shell Corner");
        if (!sCorner[i]) continue;
        SetWindowPos(sCorner[i], HWND_TOPMOST, cr[i].left, cr[i].top, R, R,
                     SWP_NOACTIVATE | (sSuppressed ? 0 : SWP_SHOWWINDOW));
        PaintCorner(sCorner[i], R, i, col);
    }
    sFrameSig = sig;
}

// Shows / hides everything that belongs to the shell (used for fullscreen apps).
static void ShowAll(bool show) {
    const int cmd = show ? SW_SHOWNOACTIVATE : SW_HIDE;
    if (sBar) ShowWindow(sBar, cmd);
    if (!show && sDash) {  // never leave the dashboard over a fullscreen app
        sDashWanted = false;
        sDashK = 1.0;
        sDashV = 0.0;
        ShowWindow(sDash, SW_HIDE);
    }
    for (HWND e : sEdge) {
        if (e) ShowWindow(e, cmd);
    }
    for (HWND c : sCorner) {
        if (c) ShowWindow(c, cmd);
    }
}

// Our own fullscreen decision (Windows' ABN_FULLSCREENAPP is only a hint). The shell hides as soon as a
// fullscreen window is seen and comes back after two consecutive "not fullscreen" checks (no flicker).
static int sFsOffCount = 0;
static void EvalFullscreen() {
    if (ForegroundCoversMonitor()) {
        sFsOffCount = 0;
        if (!sSuppressed) {
            sSuppressed = true;
            ShowAll(false);
        }
    } else if (sSuppressed) {
        if (++sFsOffCount >= 2) {
            sSuppressed = false;
            sFsOffCount = 0;
            ShowAll(cfg.bar);
        }
    }
}

static int HitAt(int x, int y) {
    for (size_t i = 0; i < sHits.size(); ++i) {
        const D2D1_RECT_F& r = sHits[i].r;
        if (x >= r.left && x < r.right && y >= r.top && y < r.bottom) return (int)i;
    }
    return -1;
}

static void Render() {
    if (!sBar || sW <= 0 || sH <= 0 || !g_dw || !EnsureRt()) return;
    const float s = (float)sScale;
    const float fk = 1.f / std::sqrt((float)cfg.scalePct / 100.f);  // text / hit-target boost

    if (!sFmt || std::fabs(sFmtScale - sScale) > 0.001) {
        SafeRelease(sEllipsis);
        SafeRelease(sFmtV);
        SafeRelease(sFmt);
        sFmt = MakeFormat(PickFontFamily(), 15.f * s * fk, DWRITE_FONT_WEIGHT_SEMI_BOLD, DWRITE_TEXT_ALIGNMENT_CENTER);
        sFmtV = MakeFormat(PickFontFamily(), 13.f * s * fk, DWRITE_FONT_WEIGHT_SEMI_BOLD, DWRITE_TEXT_ALIGNMENT_CENTER);
        if (sFmtV) {
            g_dw->CreateEllipsisTrimmingSign(sFmtV, &sEllipsis);
            const DWRITE_TRIMMING tr = {DWRITE_TRIMMING_GRANULARITY_CHARACTER, 0, 0};
            if (sEllipsis) sFmtV->SetTrimming(&tr, sEllipsis);
        }
        sFmtScale = sScale;
    }

    RECT rc = {0, 0, sW, sH};
    if (FAILED(sRt->BindDC(sDC, &rc))) return;
    sRt->BeginDraw();
    sRt->SetTransform(D2D1::Matrix3x2F::Identity());
    sRt->Clear(D2D1::ColorF(0, 0, 0, 0));
    sRt->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
    sRt->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE);

    auto brush = [&](const D2D1_COLOR_F& col, float a) {
        D2D1_COLOR_F k = col;
        k.a *= a;
        sBr->SetColor(&k);
    };
    auto rr = [&](float l, float t, float r, float b, float rad, const D2D1_COLOR_F& col, float a) {
        brush(col, a);
        D2D1_ROUNDED_RECT q = D2D1::RoundedRect(D2D1::RectF(l, t, r, b), rad, rad);
        sRt->FillRoundedRectangle(&q, sBr);
    };
    auto line = [&](float x0, float y0, float x1, float y1, const D2D1_COLOR_F& col, float a, float w) {
        brush(col, a);
        sRt->DrawLine(D2D1::Point2F(x0, y0), D2D1::Point2F(x1, y1), sBr, w, g_roundStroke);
    };
    auto dot = [&](float x, float y, float r, const D2D1_COLOR_F& col, float a) {
        brush(col, a);
        D2D1_ELLIPSE e = D2D1::Ellipse(D2D1::Point2F(x, y), r, r);
        sRt->FillEllipse(&e, sBr);
    };

    const float bw = cfg.frame ? (float)std::lround(cfg.width * sScale) : cfg.width * s;
    const float x0 = cfg.left ? 0.f : (float)sW - bw;
    const float y0 = 0.f, y1 = (float)sH;
    const float R = std::min((float)g_cfg.cornerRadius * s, bw / 2);

    // Bar body: flat on the screen edge, rounded on the side that faces the windows.
    {
        // With the frame the bar is a plain strip (the frame provides the rounded corners).
        const float rL = cfg.frame ? 0.f : (cfg.left ? 0.f : R);
        const float rR = cfg.frame ? 0.f : (cfg.left ? R : 0.f);
        if (ID2D1PathGeometry* g = MakeShapeGeo(x0, y0, bw, y1 - y0, rL, rR, rR, rL)) {
            D2D1_COLOR_F bg = g_pal.bg;
            bg.a = cfg.frame ? 1.f : std::max(bg.a, 0.92f);
            sBr->SetColor(&bg);
            sRt->FillGeometry(g, sBr);
            g->Release();
        }
    }

    sHits.clear();
    const float cx = x0 + bw / 2;
    const float btn = std::min(40.f * s, bw - 10.f * s);
    const float pad = 10.f * s;
    float y = y0 + pad;
    const HWND fg = GetForegroundWindow();

    auto addBtn = [&](int kind, HWND h) -> D2D1_RECT_F {
        D2D1_RECT_F r = D2D1::RectF(cx - btn / 2, y, cx + btn / 2, y + btn);
        sHits.push_back({r, kind, h});
        if ((int)sHits.size() - 1 == sHover) rr(r.left, r.top, r.right, r.bottom, 10.f * s, g_pal.selection, 1.f);
        y += btn + 4.f * s;
        return r;
    };

    // Start (four squares)
    {
        const D2D1_RECT_F r = addBtn(H_START, nullptr);
        const float mx = (r.left + r.right) / 2, my = (r.top + r.bottom) / 2;
        const float q = 6.f * s, gp = 1.6f * s;
        for (int ix = 0; ix < 2; ++ix) {
            for (int iy = 0; iy < 2; ++iy) {
                const float l = mx + (ix ? gp / 2 : -gp / 2 - q);
                const float t = my + (iy ? gp / 2 : -gp / 2 - q);
                rr(l, t, l + q, t + q, 1.5f * s, g_pal.text, 0.9f);
            }
        }
    }
    line(cx - btn / 2, y + 2.f * s, cx + btn / 2, y + 2.f * s, g_pal.textDim, 0.35f, 1.f);
    y += 8.f * s;

    // Bottom block: power button, the status icons, then the clock above them.
    const float powerTop = y1 - pad - btn;
    const float clockH = 17.f * s * fk;
    const float cellH = 22.f * s * fk;
    const int nStatus = cfg.status ? ((sSt.netAvail ? 1 : 0) + (sSt.hasVolume ? 1 : 0) + (sSt.hasBattery ? 1 : 0)) : 0;
    const float statusTop = powerTop - 6.f * s - nStatus * cellH;
    const float clockTop = statusTop - 8.f * s - 2 * clockH;
    const float yLimit = clockTop - 8.f * s;

    std::vector<ID2D1Bitmap*> bitmaps;
    UpdateActiveName(fg);
    const float iconSz = btn * 0.62f;
    const bool iconMode = cfg.icons;
    const float itemH = iconMode ? btn : 18.f * s * fk;      // dots are small, icons are buttons
    const float itemGap = iconMode ? 4.f * s : 0.f;
    size_t shown = 0;
    for (size_t i = 0; i < sItems.size(); ++i) {
        if (y + itemH > yLimit) break;
        const Item& it = sItems[i];
        const bool active = it.h == fg;
        const D2D1_RECT_F r = D2D1::RectF(cx - btn / 2, y, cx + btn / 2, y + itemH);
        sHits.push_back({r, H_WINDOW, it.h});
        const bool hov = ((int)sHits.size() - 1 == sHover);
        y += itemH + itemGap;
        ++shown;
        const float mx = (r.left + r.right) / 2, my = (r.top + r.bottom) / 2;
        if (!iconMode) {
            if (active) {
                rr(mx - 3.f * s, my - 7.f * s, mx + 3.f * s, my + 7.f * s, 3.f * s, g_pal.accent, 1.f);
            } else {
                dot(mx, my, hov ? 3.8f * s : 3.f * s, hov ? g_pal.text : g_pal.textDim, hov ? 0.95f : 0.65f);
            }
            continue;
        }
        if (hov) rr(r.left, r.top, r.right, r.bottom, 10.f * s, g_pal.selection, 1.f);
        if (active) {
            rr(r.left, r.top, r.right, r.bottom, 10.f * s, g_pal.accent, 0.22f);
            const float ix = cfg.left ? x0 + 3.f * s : x0 + bw - 6.f * s;
            rr(ix, r.top + 10.f * s, ix + 3.f * s, r.bottom - 10.f * s, 1.5f * s, g_pal.accent, 1.f);
        }
        bool drawn = false;
        if (!it.px.empty() && it.iw > 0 && it.ih > 0) {
            D2D1_BITMAP_PROPERTIES bp = D2D1::BitmapProperties(
                D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED), 96.f, 96.f);
            ID2D1Bitmap* bmp = nullptr;
            if (SUCCEEDED(sRt->CreateBitmap(D2D1::SizeU((UINT32)it.iw, (UINT32)it.ih), it.px.data(),
                                            (UINT32)it.iw * 4, &bp, &bmp)) &&
                bmp) {
                D2D1_RECT_F dst = D2D1::RectF(mx - iconSz / 2, my - iconSz / 2, mx + iconSz / 2, my + iconSz / 2);
                sRt->DrawBitmap(bmp, &dst, 1.f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
                bitmaps.push_back(bmp);
                drawn = true;
            }
        }
        if (!drawn) rr(mx - iconSz / 2, my - iconSz / 2, mx + iconSz / 2, my + iconSz / 2, 6.f * s, g_pal.textDim, 0.4f);
    }
    if (shown < sItems.size() && sFmt) {
        wchar_t more[16];
        swprintf_s(more, L"+%d", (int)(sItems.size() - shown));
        brush(g_pal.textDim, 1.f);
        D2D1_RECT_F mr = D2D1::RectF(x0, yLimit - clockH, x0 + bw, yLimit);
        sRt->DrawText(more, (UINT32)wcslen(more), sFmt, &mr, sBr);
    }

    // The name of the active app (or of the hovered dot) written vertically in the free middle area.
    {
        const float areaTop = y + 10.f * s;
        const float areaBottom = yLimit;
        const float areaH = areaBottom - areaTop;
        if (sFmtV && areaH > 50.f * s) {
            std::wstring label = sActiveName;
            bool hovering = false;
            if (sHover >= 0 && sHover < (int)sHits.size() && sHits[sHover].kind == H_WINDOW) {
                for (const Item& it : sItems) {
                    if (it.h == sHits[sHover].h) {
                        label = it.name;
                        hovering = true;
                        break;
                    }
                }
            }
            if (sHover >= 0 && sHover < (int)sHits.size()) {  // hovered status icon
                const std::wstring sl = StatusLabel(sHits[sHover].kind);
                if (!sl.empty()) {
                    label = sl;
                    hovering = true;
                }
            }
            IDWriteTextLayout* tl = nullptr;
            if (!label.empty() &&
                SUCCEEDED(g_dw->CreateTextLayout(label.c_str(), (UINT32)label.size(), sFmtV, areaH, bw, &tl)) && tl) {
                const DWRITE_TRIMMING tr = {DWRITE_TRIMMING_GRANULARITY_CHARACTER, 0, 0};
                if (sEllipsis) tl->SetTrimming(&tr, sEllipsis);
                const float mcy = (areaTop + areaBottom) / 2;
                sRt->SetTransform(D2D1::Matrix3x2F::Rotation(90.f, D2D1::Point2F(cx, mcy)));
                brush(hovering ? g_pal.text : g_pal.textDim, hovering ? 1.f : 0.9f);
                sRt->DrawTextLayout(D2D1::Point2F(cx - areaH / 2, mcy - bw / 2), tl, sBr);
                sRt->SetTransform(D2D1::Matrix3x2F::Identity());
                tl->Release();
            }
        }
    }

    // Clock
    if (sFmt) {
        SYSTEMTIME st;
        GetLocalTime(&st);
        int hour = st.wHour;
        if (!cfg.clock24) {
            hour %= 12;
            if (hour == 0) hour = 12;
        }
        wchar_t hh[8], mm[8];
        swprintf_s(hh, L"%02d", hour);
        swprintf_s(mm, L"%02d", (int)st.wMinute);
        brush(g_pal.text, 1.f);
        D2D1_RECT_F a = D2D1::RectF(x0, clockTop, x0 + bw, clockTop + clockH);
        sRt->DrawText(hh, 2, sFmt, &a, sBr);
        brush(g_pal.textDim, 1.f);
        D2D1_RECT_F b = D2D1::RectF(x0, clockTop + clockH, x0 + bw, clockTop + 2 * clockH);
        sRt->DrawText(mm, 2, sFmt, &b, sBr);
    }

    // Status icons: network, volume, battery
    if (nStatus > 0) {
        float yy = statusTop;
        const float u = 7.f * s * fk;
        auto arcL = [&](float acx, float acy, float rad, double a0d, double a1d, const D2D1_COLOR_F& col, float a) {
            const int kSeg = 14;
            const double a0 = a0d * kPi / 180.0, a1 = a1d * kPi / 180.0;
            D2D1_POINT_2F prev = D2D1::Point2F(acx + rad * (float)std::cos(a0), acy + rad * (float)std::sin(a0));
            for (int i = 1; i <= kSeg; ++i) {
                const double an = a0 + (a1 - a0) * i / kSeg;
                const D2D1_POINT_2F p = D2D1::Point2F(acx + rad * (float)std::cos(an), acy + rad * (float)std::sin(an));
                line(prev.x, prev.y, p.x, p.y, col, a, 1.5f * s);
                prev = p;
            }
        };
        auto cell = [&](int kind) -> D2D1_RECT_F {
            D2D1_RECT_F r = D2D1::RectF(cx - btn / 2, yy, cx + btn / 2, yy + cellH);
            sHits.push_back({r, kind, nullptr});
            if ((int)sHits.size() - 1 == sHover) rr(r.left, r.top, r.right, r.bottom, 8.f * s, g_pal.selection, 1.f);
            yy += cellH;
            return r;
        };

        if (sSt.netAvail) {
            const D2D1_RECT_F r = cell(H_WIFI);
            const float mx = (r.left + r.right) / 2, my = (r.top + r.bottom) / 2;
            if (sSt.net == 2) {
                rr(mx - u * 0.9f, my - u * 0.7f, mx + u * 0.9f, my + u * 0.3f, 2.f * s, g_pal.text, 0.9f);
                line(mx, my + u * 0.3f, mx, my + u * 0.8f, g_pal.text, 0.9f, 1.6f * s);
                line(mx - u * 0.6f, my + u * 0.8f, mx + u * 0.6f, my + u * 0.8f, g_pal.text, 0.9f, 1.6f * s);
            } else {
                const int lit = sSt.net == 1 ? (sSt.wifiQuality > 66 ? 3 : (sSt.wifiQuality > 33 ? 2 : 1)) : 0;
                const float by2 = my + u * 0.85f;
                const float radii[3] = {u * 0.6f, u * 1.05f, u * 1.5f};
                for (int k = 0; k < 3; ++k) {
                    arcL(mx, by2, radii[k], -135.0, -45.0, k < lit ? g_pal.text : g_pal.textDim, k < lit ? 0.95f : 0.35f);
                }
                dot(mx, by2, 1.5f * s, sSt.net == 0 ? g_pal.textDim : g_pal.text, sSt.net == 0 ? 0.5f : 0.95f);
                if (sSt.net == 0) line(mx - u, my - u * 0.9f, mx + u, my + u, g_pal.text, 0.9f, 1.6f * s);
            }
        }

        if (sSt.hasVolume) {
            const D2D1_RECT_F r = cell(H_VOLUME);
            const float mx = (r.left + r.right) / 2, my = (r.top + r.bottom) / 2;
            const float xa = mx - u * 0.95f, xb = mx - u * 0.45f, xc = mx + u * 0.05f;
            const float lw = 1.5f * s;
            line(xa, my - u * 0.35f, xb, my - u * 0.35f, g_pal.text, 0.95f, lw);
            line(xb, my - u * 0.35f, xc, my - u * 0.8f, g_pal.text, 0.95f, lw);
            line(xc, my - u * 0.8f, xc, my + u * 0.8f, g_pal.text, 0.95f, lw);
            line(xc, my + u * 0.8f, xb, my + u * 0.35f, g_pal.text, 0.95f, lw);
            line(xb, my + u * 0.35f, xa, my + u * 0.35f, g_pal.text, 0.95f, lw);
            line(xa, my + u * 0.35f, xa, my - u * 0.35f, g_pal.text, 0.95f, lw);
            if (sSt.muted || sSt.volume <= 0.001f) {
                line(xc + u * 0.4f, my - u * 0.4f, xc + u * 1.0f, my + u * 0.4f, g_pal.text, 0.95f, lw);
                line(xc + u * 0.4f, my + u * 0.4f, xc + u * 1.0f, my - u * 0.4f, g_pal.text, 0.95f, lw);
            } else {
                arcL(xc, my, u * 0.6f, -40.0, 40.0, g_pal.text, 0.95f);
                if (sSt.volume > 0.5f) arcL(xc, my, u * 1.0f, -40.0, 40.0, g_pal.text, 0.95f);
            }
        }

        if (sSt.hasBattery) {
            const D2D1_RECT_F r = cell(H_BATTERY);
            const float mx = (r.left + r.right) / 2, my = (r.top + r.bottom) / 2;
            const float bl = mx - u * 1.2f, br = mx + u * 0.95f, bt = my - u * 0.55f, bb = my + u * 0.55f;
            brush(g_pal.text, 0.9f);
            D2D1_ROUNDED_RECT q = D2D1::RoundedRect(D2D1::RectF(bl, bt, br, bb), 2.f * s, 2.f * s);
            sRt->DrawRoundedRectangle(&q, sBr, 1.3f * s);
            rr(br + 0.6f * s, my - u * 0.25f, br + u * 0.3f, my + u * 0.25f, 1.f * s, g_pal.text, 0.9f);
            const float pad2 = 1.8f * s;
            const float fw = (br - bl - 2 * pad2) * (float)std::clamp(sSt.batPct, 0, 100) / 100.f;
            D2D1_COLOR_F fillc = g_pal.accent;
            if (sSt.batPct <= 15 && !sSt.ac) fillc = D2D1::ColorF(0.95f, 0.32f, 0.32f, 1.f);
            if (fw > 0.5f) rr(bl + pad2, bt + pad2, bl + pad2 + fw, bb - pad2, 1.f * s, fillc, 1.f);
            if (sSt.ac) {  // charging / plugged in: small bolt
                const D2D1_COLOR_F white = D2D1::ColorF(1.f, 1.f, 1.f, 1.f);
                line(mx + u * 0.15f, my - u * 0.45f, mx - u * 0.3f, my + u * 0.05f, white, 0.95f, 1.3f * s);
                line(mx - u * 0.3f, my + u * 0.05f, mx + u * 0.1f, my + u * 0.05f, white, 0.95f, 1.3f * s);
                line(mx + u * 0.1f, my + u * 0.05f, mx - u * 0.2f, my + u * 0.45f, white, 0.95f, 1.3f * s);
            }
        }
    }

    // Power (opens the launcher in ">" mode)
    {
        const D2D1_RECT_F r = D2D1::RectF(cx - btn / 2, powerTop, cx + btn / 2, powerTop + btn);
        sHits.push_back({r, H_POWER, nullptr});
        if ((int)sHits.size() - 1 == sHover) rr(r.left, r.top, r.right, r.bottom, 10.f * s, g_pal.selection, 1.f);
        const float mx = (r.left + r.right) / 2, my = (r.top + r.bottom) / 2, pr = 7.f * s;
        const int kSeg = 24;
        const double a0 = (-90.0 + 40.0) * kPi / 180.0, a1 = (-90.0 + 320.0) * kPi / 180.0;
        D2D1_POINT_2F prev = D2D1::Point2F(mx + pr * (float)std::cos(a0), my + 1.f * s + pr * (float)std::sin(a0));
        for (int i = 1; i <= kSeg; ++i) {
            const double a = a0 + (a1 - a0) * i / kSeg;
            const D2D1_POINT_2F p = D2D1::Point2F(mx + pr * (float)std::cos(a), my + 1.f * s + pr * (float)std::sin(a));
            brush(g_pal.text, 0.9f);
            sRt->DrawLine(prev, p, sBr, 2.f * s, g_roundStroke);
            prev = p;
        }
        line(mx, my - pr, mx, my + 1.f * s, g_pal.text, 0.9f, 2.f * s);
    }

    HRESULT hr = sRt->EndDraw();
    for (ID2D1Bitmap* b : bitmaps) b->Release();
    if (hr == D2DERR_RECREATE_TARGET) {
        SafeRelease(sBr);
        SafeRelease(sRt);
    }

    SIZE sz = {sW, sH};
    POINT src = {0, 0};
    BLENDFUNCTION bf = {};
    bf.BlendOp = AC_SRC_OVER;
    bf.SourceConstantAlpha = 255;
    bf.AlphaFormat = AC_SRC_ALPHA;
    UpdateLayeredWindow(sBar, nullptr, nullptr, &sz, sDC, &src, 0, &bf, ULW_ALPHA);
}

// ---------------------------------------------------------------- AppBar placement
static void RegisterBar() {
    if (sRegistered || !sBar) return;
    APPBARDATA abd = {};
    abd.cbSize = sizeof(abd);
    abd.hWnd = sBar;
    abd.uCallbackMessage = WM_APPBAR_CB;
    if (SHAppBarMessage(ABM_NEW, &abd)) sRegistered = true;
}

static void UnregisterBar() {
    if (!sRegistered || !sBar) return;
    APPBARDATA abd = {};
    abd.cbSize = sizeof(abd);
    abd.hWnd = sBar;
    SHAppBarMessage(ABM_REMOVE, &abd);
    sRegistered = false;
}

static void PositionBar() {
    if (!sBar || !cfg.bar) return;
    HMONITOR mon = MonitorFromPoint(POINT{0, 0}, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFO mi = {};
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfoW(mon, &mi)) return;
    sScale = MonitorScale(mon) * (cfg.scalePct / 100.0);  // independent from the launcher size

    const double dpiNow = MonitorScale(mon);
    const int thick = cfg.frame ? (int)std::lround(cfg.width * sScale) + (int)std::lround(cfg.windowGap * dpiNow)
                                : (int)std::lround((cfg.width + cfg.gap) * sScale);
    APPBARDATA abd = {};
    abd.cbSize = sizeof(abd);
    abd.hWnd = sBar;
    abd.uEdge = cfg.left ? ABE_LEFT : ABE_RIGHT;
    abd.rc = mi.rcMonitor;
    if (cfg.left) {
        abd.rc.right = abd.rc.left + thick;
    } else {
        abd.rc.left = abd.rc.right - thick;
    }
    SHAppBarMessage(ABM_QUERYPOS, &abd);
    if (cfg.flush) abd.rc = mi.rcMonitor;  // stay glued to the real screen edge
    if (cfg.left) {
        abd.rc.right = abd.rc.left + thick;
    } else {
        abd.rc.left = abd.rc.right - thick;
    }
    if (!EqualRect(&sRect, &abd.rc)) {  // only when something changed (avoids AppBar notification loops)
        SHAppBarMessage(ABM_SETPOS, &abd);
        sAbnIgnoreUntil = GetTickCount64() + 800;
    }

    const bool same = EqualRect(&sRect, &abd.rc) && IsWindowVisible(sBar);
    sRect = abd.rc;
    if (!same) {
        SetWindowPos(sBar, HWND_TOPMOST, sRect.left, sRect.top, sRect.right - sRect.left,
                     sRect.bottom - sRect.top, SWP_NOACTIVATE | (sSuppressed ? 0 : SWP_SHOWWINDOW));
    }
    if (EnsureSurface(sRect.right - sRect.left, sRect.bottom - sRect.top)) Render();
    {   // inner area (inside the bar / frame): the launcher docks to it
        const double dpi2 = MonitorScale(mon);
        const int barPx2 = (int)std::lround(cfg.width * sScale);
        const int T2 = cfg.frame ? (int)std::lround(cfg.frameThick * dpi2) : 0;
        const int il2 = cfg.left ? barPx2 : T2;
        const int ir2 = cfg.left ? T2 : barPx2;
        sInner = RECT{mi.rcMonitor.left + il2, mi.rcMonitor.top + T2, mi.rcMonitor.right - ir2,
                      mi.rcMonitor.bottom - T2};
        sMonRect = mi.rcMonitor;
        sInnerValid = true;
    }
    PositionFrame(mi.rcMonitor);
}

static void Apply() {
    LoadCfg();
    LoadPalette();
    if (!sBar) return;
    if (!cfg.bar) {
        KillTimer(sBar, T_TICK);
        UnhookShell();
        UnregisterBar();
        ShowWindow(sBar, SW_HIDE);
        TeardownFrame();
        DashApply();
        RemoveEvHook();
        SetTaskbarHidden(false);
        return;
    }
    RegisterBar();
    HookShell();
    if (cfg.hideTaskbar && !sRevealed) {
        SetTaskbarHidden(true);
        InstallEvHook();
    } else {
        RemoveEvHook();
        SetTaskbarHidden(false);
    }
    if (cfg.status) {
        StartNetThread();
        PollStatus(true);
    } else {
        StopNetThread();
    }
    sItems.clear();  // re-evaluate every window with the new settings
    sIgnored.clear();
    RefreshItems();
    sRect = RECT{};  // force a re-placement with the new settings
    PositionBar();
    DashApply();
    SetTimer(sBar, T_TICK, 500, nullptr);
}

// ---------------------------------------------------------------- input
// ===== Dashboard: a panel that grows out of the top of the frame =====
static HDC sdDC = nullptr;
static HBITMAP sdDib = nullptr;
static HGDIOBJ sdOld = nullptr;
static int sdW = 0, sdH = 0;
static ID2D1DCRenderTarget* sdRt = nullptr;
static ID2D1SolidColorBrush* sdBr = nullptr;
static IDWriteTextFormat* sdFmtTab = nullptr;
static IDWriteTextFormat* sdFmtBig = nullptr;
static IDWriteTextFormat* sdFmtSmall = nullptr;
static double sdFmtScale = 0;
static bool sDashViaEdge = false;   // opened by the cursor: closes when the cursor leaves
static bool sdTracking = false;
static int sDashTab = 0;
static int sDashHover = -1;
static std::vector<RECT> sDashTabRects;
struct DashCtl {
    RECT r;
    int kind;  // 1 calendar previous, 2 calendar next, 3 calendar title, 4 volume slider, 5 mute button
};
static std::vector<DashCtl> sDashCtl;
static int sDashCtlHover = -1;
static RECT sSliderRect = {};   // extent of the volume track (window coordinates)
static bool sVolDrag = false;
static int sCalOffset = 0;      // months away from the current month
static ULONGLONG sEdgeSince = 0;    // when the cursor entered the hot zone
static bool sEdgeArmed = true;      // after a close the cursor must leave the hot zone before it can reopen
static ULONGLONG sOutsideSince = 0;
static int sdLastMinute = -1;
static const wchar_t* const kDashTabs[3] = {L"Dashboard", L"Media", L"Performance"};

static bool DashEnsureSurface(int w, int h) {
    if (sdDib && w == sdW && h == sdH) return true;
    if (!sdDC) sdDC = CreateCompatibleDC(nullptr);
    if (sdDib) {
        SelectObject(sdDC, sdOld);
        DeleteObject(sdDib);
        sdDib = nullptr;
    }
    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = w;
    bi.bmiHeader.biHeight = -h;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    sdDib = CreateDIBSection(nullptr, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (!sdDib) return false;
    sdOld = SelectObject(sdDC, sdDib);
    sdW = w;
    sdH = h;
    return true;
}

static bool DashEnsureRt() {
    if (sdRt && sdBr) return true;
    SafeRelease(sdBr);
    SafeRelease(sdRt);
    if (!g_d2d) return false;
    D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_DEFAULT,
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED), 96.f, 96.f,
        D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT);
    if (FAILED(g_d2d->CreateDCRenderTarget(&props, &sdRt)) || !sdRt) return false;
    sdRt->SetDpi(96.f, 96.f);
    sdRt->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 1), &sdBr);
    return sdBr != nullptr;
}

static void RenderDash() {
    if (!sDash || sdW <= 0 || sdH <= 0 || !g_dw || !g_d2d || !DashEnsureRt()) return;
    const double dpi = MonitorScale(MonitorFromPoint(POINT{0, 0}, MONITOR_DEFAULTTOPRIMARY));
    const float s = (float)dpi;
    if (!sdFmtTab || std::fabs(sdFmtScale - dpi) > 0.001) {
        SafeRelease(sdFmtTab);
        SafeRelease(sdFmtBig);
        SafeRelease(sdFmtSmall);
        sdFmtTab = MakeFormat(PickFontFamily(), 13.f * s, DWRITE_FONT_WEIGHT_SEMI_BOLD, DWRITE_TEXT_ALIGNMENT_CENTER);
        sdFmtBig = MakeFormat(PickFontFamily(), 52.f * s, DWRITE_FONT_WEIGHT_SEMI_BOLD, DWRITE_TEXT_ALIGNMENT_CENTER);
        sdFmtSmall = MakeFormat(PickFontFamily(), 15.f * s, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_TEXT_ALIGNMENT_CENTER);
        sdFmtScale = dpi;
    }
    const int fl = (int)std::lround(cfg.frameRadius * dpi);  // width of the flares on each side
    const float pw = (float)(sdW - 2 * fl);                  // panel width
    // The card always has its full size; the animation (same style as the launcher) moves / scales / fades it.
    const float curH = (float)sdH;
    const bool dashSlide = g_cfg.anim == AnimStyle::SlideBottom || g_cfg.anim == AnimStyle::SlideTop ||
                           g_cfg.anim == AnimStyle::SlideLeft || g_cfg.anim == AnimStyle::SlideRight;
    const bool dashFade = g_cfg.animFade || g_cfg.anim == AnimStyle::Fade || g_cfg.anim == AnimStyle::Popup;
    const double dashAlpha = dashFade ? std::clamp(1.0 - sDashK, 0.0, 1.0) : 1.0;

    RECT rc = {0, 0, sdW, sdH};
    if (FAILED(sdRt->BindDC(sdDC, &rc))) return;
    sdRt->BeginDraw();
    sdRt->SetTransform(D2D1::Matrix3x2F::Identity());
    sdRt->Clear(D2D1::ColorF(0, 0, 0, 0));
    sdRt->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
    sdRt->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE);
    if (dashSlide) {
        // slide from the top edge (the edge the dashboard is docked to); the window edge clips it
        sdRt->SetTransform(D2D1::Matrix3x2F::Translation(0.f, -(float)sdH * (float)std::clamp(sDashK, 0.0, 1.0)));
    } else if (g_cfg.anim == AnimStyle::Popup) {
        const float sc = (float)(1.0 + (0.9 - 1.0) * sDashK);  // 0.9 -> 1.0 like the launcher, from the docked edge
        sdRt->SetTransform(D2D1::Matrix3x2F::Scale(sc, sc, D2D1::Point2F((float)sdW / 2.f, 0.f)));
    }
    sDashTabRects.assign(3, RECT{0, 0, 0, 0});

    if (curH >= 2.f) {
        // Flat top (docked to the frame), rounded bottom corners, concave flares joining the frame.
        const float R = std::min((float)fl, curH);
        ID2D1PathGeometry* shape = MakeShapeGeo((float)fl, 0.f, pw, curH, 0.f, 0.f, R, R);
        if (shape && R >= 1.f) {
            shape = AddFlare(shape, (float)fl - R, 0.f, (float)fl, 0.f, (float)fl, R,
                             D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE, R);
            shape = AddFlare(shape, (float)fl + pw + R, 0.f, (float)fl + pw, 0.f, (float)fl + pw, R,
                             D2D1_SWEEP_DIRECTION_CLOCKWISE, R);
        }
        if (shape) {
            D2D1_COLOR_F bg = g_pal.bg;
            bg.a = 1.f;  // same opaque colour as the frame
            sdBr->SetColor(&bg);
            sdRt->FillGeometry(shape, sdBr);
            shape->Release();
        }

        // Content fades in while the panel grows.
        const float ca = 1.f;
        D2D1_RECT_F clip = D2D1::RectF((float)fl, 0.f, (float)fl + pw, curH);
        sdRt->PushAxisAlignedClip(&clip, D2D1_ANTIALIAS_MODE_ALIASED);
        auto brush = [&](const D2D1_COLOR_F& col, float a) {
            D2D1_COLOR_F k = col;
            k.a *= a * ca;
            sdBr->SetColor(&k);
        };

        const float tabH = 40.f * s;
        const float tabW = pw / 3.f;
        for (int i = 0; i < 3; ++i) {
            D2D1_RECT_F tr = D2D1::RectF((float)fl + i * tabW, 0.f, (float)fl + (i + 1) * tabW, tabH);
            sDashTabRects[i] = RECT{(LONG)tr.left, (LONG)tr.top, (LONG)tr.right, (LONG)tr.bottom};
            const bool active = i == sDashTab;
            const bool hov = i == sDashHover;
            brush((active || hov) ? g_pal.text : g_pal.textDim, active ? 1.f : (hov ? 0.95f : 0.8f));
            sdRt->DrawText(kDashTabs[i], (UINT32)wcslen(kDashTabs[i]), sdFmtTab, &tr, sdBr);
            if (active) {
                brush(g_pal.accent, 1.f);
                const float mx = (tr.left + tr.right) / 2;
                D2D1_ROUNDED_RECT u = D2D1::RoundedRect(
                    D2D1::RectF(mx - 14.f * s, tabH - 5.f * s, mx + 14.f * s, tabH - 2.5f * s), 1.5f * s, 1.5f * s);
                sdRt->FillRoundedRectangle(&u, sdBr);
            }
        }
        brush(g_pal.textDim, 0.25f);
        D2D1_RECT_F sep = D2D1::RectF((float)fl + 16.f * s, tabH, (float)fl + pw - 16.f * s, tabH + 1.f);
        sdRt->FillRectangle(&sep, sdBr);

        const float areaTop = tabH + 8.f * s;
        sDashCtl.clear();
        sSliderRect = RECT{0, 0, 0, 0};
        auto fillRR = [&](float l, float t, float r, float b, float rad, const D2D1_COLOR_F& col, float a) {
            brush(col, a);
            D2D1_ROUNDED_RECT q = D2D1::RoundedRect(D2D1::RectF(l, t, r, b), rad, rad);
            sdRt->FillRoundedRectangle(&q, sdBr);
        };
        auto ln = [&](float x0, float y0, float x1, float y1, const D2D1_COLOR_F& col, float a, float w) {
            brush(col, a);
            sdRt->DrawLine(D2D1::Point2F(x0, y0), D2D1::Point2F(x1, y1), sdBr, w, g_roundStroke);
        };
        auto dotC = [&](float x, float y, float r, const D2D1_COLOR_F& col, float a) {
            brush(col, a);
            D2D1_ELLIPSE e = D2D1::Ellipse(D2D1::Point2F(x, y), r, r);
            sdRt->FillEllipse(&e, sdBr);
        };
        auto addCtl = [&](int kind, float l, float t, float r, float b) -> int {
            sDashCtl.push_back({RECT{(LONG)l, (LONG)t, (LONG)r, (LONG)b}, kind});
            return (int)sDashCtl.size() - 1;
        };

        if (sDashTab == 0) {
            SYSTEMTIME now;
            GetLocalTime(&now);
            sdLastMinute = now.wMinute;
            const float top = areaTop + 4.f * s;
            const float bottom = curH - 14.f * s;
            const float x0 = (float)fl + 16.f * s;
            const float x1 = (float)fl + pw - 16.f * s;
            const float totalW = x1 - x0;
            const float leftW = totalW * 0.32f;
            const float volW = totalW * 0.16f;
            const float calX0 = x0 + leftW + 8.f * s;
            const float calX1 = x1 - volW - 8.f * s;

            // ---- clock + date
            {
                int hour = now.wHour;
                if (!cfg.clock24) {
                    hour %= 12;
                    if (hour == 0) hour = 12;
                }
                wchar_t hm[16] = {};
                swprintf_s(hm, L"%02d:%02d", hour, (int)now.wMinute);
                wchar_t dayName[64] = {}, dateLine[64] = {};
                GetDateFormatW(LOCALE_USER_DEFAULT, 0, &now, L"dddd", dayName, ARRAYSIZE(dayName));
                GetDateFormatW(LOCALE_USER_DEFAULT, 0, &now, L"d MMMM yyyy", dateLine, ARRAYSIZE(dateLine));
                brush(g_pal.text, 1.f);
                D2D1_RECT_F r1 = D2D1::RectF(x0, top + 30.f * s, x0 + leftW, top + 100.f * s);
                sdRt->DrawText(hm, (UINT32)wcslen(hm), sdFmtBig, &r1, sdBr);
                brush(g_pal.text, 0.9f);
                D2D1_RECT_F r2 = D2D1::RectF(x0, top + 104.f * s, x0 + leftW, top + 128.f * s);
                sdRt->DrawText(dayName, (UINT32)wcslen(dayName), sdFmtTab, &r2, sdBr);
                brush(g_pal.textDim, 1.f);
                D2D1_RECT_F r3 = D2D1::RectF(x0, top + 128.f * s, x0 + leftW, top + 152.f * s);
                sdRt->DrawText(dateLine, (UINT32)wcslen(dateLine), sdFmtSmall, &r3, sdBr);
            }

            // ---- calendar
            {
                const int month0 = (int)now.wMonth - 1 + sCalOffset;
                const int yAdj = (month0 >= 0) ? month0 / 12 : -((11 - month0) / 12);
                const int year = (int)now.wYear + yAdj;
                const int month = month0 - yAdj * 12 + 1;
                SYSTEMTIME first = {};
                first.wYear = (WORD)year;
                first.wMonth = (WORD)month;
                first.wDay = 1;
                FILETIME ft;
                if (SystemTimeToFileTime(&first, &ft)) FileTimeToSystemTime(&ft, &first);  // fills wDayOfWeek
                DWORD lfd = 0;  // locale: 0 = Monday ... 6 = Sunday
                if (!GetLocaleInfoW(LOCALE_USER_DEFAULT, LOCALE_IFIRSTDAYOFWEEK | LOCALE_RETURN_NUMBER, (LPWSTR)&lfd, 2)) {
                    lfd = 0;
                }
                const int fdow = (int)((lfd + 1) % 7);  // first weekday, 0 = Sunday
                const int startCol = ((int)first.wDayOfWeek - fdow + 7) % 7;
                static const int kDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                const bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
                const int daysIn = kDays[month - 1] + ((month == 2 && leap) ? 1 : 0);

                const float calW = calX1 - calX0;
                const float cellW = calW / 7.f;
                const float headH = 28.f * s, wdH = 22.f * s;
                const float gridTop = top + headH + wdH;
                const float cellH = std::min((bottom - gridTop) / 6.f, 34.f * s);

                // header: arrows + title
                {
                    const D2D1_RECT_F pr = D2D1::RectF(calX0, top, calX0 + 28.f * s, top + headH);
                    const D2D1_RECT_F nr = D2D1::RectF(calX1 - 28.f * s, top, calX1, top + headH);
                    const D2D1_RECT_F tr = D2D1::RectF(calX0 + 32.f * s, top, calX1 - 32.f * s, top + headH);
                    const int idPrev = addCtl(1, pr.left, pr.top, pr.right, pr.bottom);
                    const int idNext = addCtl(2, nr.left, nr.top, nr.right, nr.bottom);
                    const int idTitle = addCtl(3, tr.left, tr.top, tr.right, tr.bottom);
                    if (sDashCtlHover == idPrev) fillRR(pr.left, pr.top + 2.f * s, pr.right, pr.bottom - 2.f * s, 8.f * s, g_pal.selection, 1.f);
                    if (sDashCtlHover == idNext) fillRR(nr.left, nr.top + 2.f * s, nr.right, nr.bottom - 2.f * s, 8.f * s, g_pal.selection, 1.f);
                    const float pcx = (pr.left + pr.right) / 2, ncx = (nr.left + nr.right) / 2, cyh = top + headH / 2;
                    ln(pcx + 3.f * s, cyh - 6.f * s, pcx - 3.f * s, cyh, g_pal.text, 0.9f, 1.6f * s);
                    ln(pcx - 3.f * s, cyh, pcx + 3.f * s, cyh + 6.f * s, g_pal.text, 0.9f, 1.6f * s);
                    ln(ncx - 3.f * s, cyh - 6.f * s, ncx + 3.f * s, cyh, g_pal.text, 0.9f, 1.6f * s);
                    ln(ncx + 3.f * s, cyh, ncx - 3.f * s, cyh + 6.f * s, g_pal.text, 0.9f, 1.6f * s);
                    wchar_t title[64] = {};
                    GetDateFormatW(LOCALE_USER_DEFAULT, 0, &first, L"MMMM yyyy", title, ARRAYSIZE(title));
                    brush(g_pal.text, sDashCtlHover == idTitle ? 1.f : 0.95f);
                    D2D1_RECT_F tt = tr;
                    sdRt->DrawText(title, (UINT32)wcslen(title), sdFmtTab, &tt, sdBr);
                }
                // weekday names
                for (int c = 0; c < 7; ++c) {
                    SYSTEMTIME ref = {};
                    ref.wYear = 2023;
                    ref.wMonth = 1;
                    ref.wDay = (WORD)(1 + (fdow + c) % 7);  // 2023-01-01 is a Sunday
                    wchar_t nm[16] = {};
                    GetDateFormatW(LOCALE_USER_DEFAULT, 0, &ref, L"ddd", nm, ARRAYSIZE(nm));
                    const std::wstring two = std::wstring(nm).substr(0, 2);
                    brush(g_pal.textDim, 0.85f);
                    D2D1_RECT_F wr = D2D1::RectF(calX0 + c * cellW, top + headH, calX0 + (c + 1) * cellW, top + headH + wdH);
                    sdRt->DrawText(two.c_str(), (UINT32)two.size(), sdFmtTab, &wr, sdBr);
                }
                // days
                for (int d = 1; d <= daysIn; ++d) {
                    const int idx = startCol + d - 1;
                    const int row = idx / 7, col = idx % 7;
                    D2D1_RECT_F cr = D2D1::RectF(calX0 + col * cellW, gridTop + row * cellH, calX0 + (col + 1) * cellW,
                                                 gridTop + (row + 1) * cellH);
                    const bool today = sCalOffset == 0 && d == (int)now.wDay;
                    if (today) dotC((cr.left + cr.right) / 2, (cr.top + cr.bottom) / 2, std::min(cellW, cellH) * 0.42f, g_pal.accent, 1.f);
                    wchar_t num[8] = {};
                    swprintf_s(num, L"%d", d);
                    if (today) {
                        brush(D2D1::ColorF(1.f, 1.f, 1.f, 1.f), 1.f);
                    } else {
                        brush(g_pal.text, 0.9f);
                    }
                    sdRt->DrawText(num, (UINT32)wcslen(num), sdFmtTab, &cr, sdBr);
                }
            }

            // ---- volume
            {
                const float vx0 = x1 - volW;
                const float cx = (vx0 + x1) / 2;
                if (!sSt.hasVolume) {
                    brush(g_pal.textDim, 1.f);
                    const wchar_t* nv = L"No audio";
                    D2D1_RECT_F nr = D2D1::RectF(vx0, top + 60.f * s, x1, top + 90.f * s);
                    sdRt->DrawText(nv, (UINT32)wcslen(nv), sdFmtTab, &nr, sdBr);
                } else {
                    const float topY = top + 26.f * s;
                    const float botY = bottom - 58.f * s;
                    const float trackW = 8.f * s;
                    wchar_t pct[16] = {};
                    swprintf_s(pct, L"%d%%", (int)std::lround(sSt.volume * 100.f));
                    brush(sSt.muted ? g_pal.textDim : g_pal.text, 1.f);
                    D2D1_RECT_F pr = D2D1::RectF(vx0, top, x1, top + 22.f * s);
                    sdRt->DrawText(pct, (UINT32)wcslen(pct), sdFmtTab, &pr, sdBr);

                    fillRR(cx - trackW / 2, topY, cx + trackW / 2, botY, trackW / 2, g_pal.textDim, 0.3f);
                    const float fillTop = botY - (botY - topY) * std::clamp(sSt.volume, 0.f, 1.f);
                    if (botY - fillTop > 0.5f) {
                        fillRR(cx - trackW / 2, fillTop, cx + trackW / 2, botY, trackW / 2,
                               sSt.muted ? g_pal.textDim : g_pal.accent, 1.f);
                    }
                    dotC(cx, fillTop, 8.f * s, sSt.muted ? g_pal.textDim : g_pal.text, 1.f);
                    addCtl(4, cx - 16.f * s, topY - 8.f * s, cx + 16.f * s, botY + 8.f * s);
                    sSliderRect = RECT{(LONG)(cx - 16.f * s), (LONG)topY, (LONG)(cx + 16.f * s), (LONG)botY};

                    // mute button
                    const D2D1_RECT_F mr = D2D1::RectF(cx - 17.f * s, botY + 16.f * s, cx + 17.f * s, botY + 50.f * s);
                    const int idMute = addCtl(5, mr.left, mr.top, mr.right, mr.bottom);
                    if (sDashCtlHover == idMute) fillRR(mr.left, mr.top, mr.right, mr.bottom, 9.f * s, g_pal.selection, 1.f);
                    const float mx = (mr.left + mr.right) / 2, my = (mr.top + mr.bottom) / 2, u = 7.f * s;
                    const float xa = mx - u * 0.95f, xb = mx - u * 0.45f, xc = mx + u * 0.05f, lw = 1.5f * s;
                    ln(xa, my - u * 0.35f, xb, my - u * 0.35f, g_pal.text, 0.95f, lw);
                    ln(xb, my - u * 0.35f, xc, my - u * 0.8f, g_pal.text, 0.95f, lw);
                    ln(xc, my - u * 0.8f, xc, my + u * 0.8f, g_pal.text, 0.95f, lw);
                    ln(xc, my + u * 0.8f, xb, my + u * 0.35f, g_pal.text, 0.95f, lw);
                    ln(xb, my + u * 0.35f, xa, my + u * 0.35f, g_pal.text, 0.95f, lw);
                    ln(xa, my + u * 0.35f, xa, my - u * 0.35f, g_pal.text, 0.95f, lw);
                    if (sSt.muted || sSt.volume <= 0.001f) {
                        ln(xc + u * 0.4f, my - u * 0.4f, xc + u * 1.0f, my + u * 0.4f, g_pal.text, 0.95f, lw);
                        ln(xc + u * 0.4f, my + u * 0.4f, xc + u * 1.0f, my - u * 0.4f, g_pal.text, 0.95f, lw);
                    } else {
                        ln(xc + u * 0.5f, my - u * 0.35f, xc + u * 0.8f, my - u * 0.6f, g_pal.text, 0.95f, lw);
                        ln(xc + u * 0.5f, my + u * 0.35f, xc + u * 0.8f, my + u * 0.6f, g_pal.text, 0.95f, lw);
                    }
                }
            }
        } else {
            brush(g_pal.textDim, 1.f);
            const wchar_t* msg = L"Coming next";
            D2D1_RECT_F r = D2D1::RectF((float)fl, areaTop + 60.f * s, (float)fl + pw, areaTop + 100.f * s);
            sdRt->DrawText(msg, (UINT32)wcslen(msg), sdFmtSmall, &r, sdBr);
        }
        sdRt->PopAxisAlignedClip();
    }

    const HRESULT hr = sdRt->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET) {
        SafeRelease(sdBr);
        SafeRelease(sdRt);
    }
    SIZE sz = {sdW, sdH};
    POINT src = {0, 0};
    BLENDFUNCTION bf = {};
    bf.BlendOp = AC_SRC_OVER;
    bf.SourceConstantAlpha = (BYTE)std::clamp((int)std::lround(dashAlpha * 255.0), 0, 255);
    bf.AlphaFormat = AC_SRC_ALPHA;
    UpdateLayeredWindow(sDash, nullptr, nullptr, &sz, sdDC, &src, 0, &bf, ULW_ALPHA);
}

static int DashHitCtl(int x, int y) {
    const POINT p = {x, y};
    for (size_t i = 0; i < sDashCtl.size(); ++i) {
        if (PtInRect(&sDashCtl[i].r, p)) return (int)i;
    }
    return -1;
}

static void DashSetVolumeFromY(int y) {
    if (!sEpVol || sSliderRect.bottom <= sSliderRect.top) return;
    float v = 1.f - (float)(y - sSliderRect.top) / (float)(sSliderRect.bottom - sSliderRect.top);
    v = std::clamp(v, 0.f, 1.f);
    sEpVol->SetMasterVolumeLevelScalar(v, nullptr);
    if (v > 0.f && sSt.muted) sEpVol->SetMute(FALSE, nullptr);
    sSt.volume = v;
    if (v > 0.f) sSt.muted = false;
    RenderDash();
}

static void DashNudgeVolume(bool up) {
    if (!sEpVol) return;
    const float v = std::clamp(sSt.volume + (up ? 0.05f : -0.05f), 0.f, 1.f);
    sEpVol->SetMasterVolumeLevelScalar(v, nullptr);
    if (up && sSt.muted) sEpVol->SetMute(FALSE, nullptr);
    PollVolume();
    RenderDash();
}

static LRESULT CALLBACK DashProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
        case WM_MOUSEACTIVATE:
            return MA_NOACTIVATE;
        case WM_MOUSEMOVE: {
            const int x = GET_X_LPARAM(l), y = GET_Y_LPARAM(l);
            if (sVolDrag) {
                DashSetVolumeFromY(y);
                return 0;
            }
            if (!sdTracking) {
                TRACKMOUSEEVENT t = {sizeof(t), TME_LEAVE, h, 0};
                TrackMouseEvent(&t);
                sdTracking = true;
            }
            const POINT p = {x, y};
            int hv = -1;
            for (size_t i = 0; i < sDashTabRects.size(); ++i) {
                if (PtInRect(&sDashTabRects[i], p)) hv = (int)i;
            }
            const int hc = DashHitCtl(x, y);
            if (hv != sDashHover || hc != sDashCtlHover) {
                sDashHover = hv;
                sDashCtlHover = hc;
                RenderDash();
            }
            return 0;
        }
        case WM_MOUSELEAVE:
            sdTracking = false;
            if (sDashHover != -1 || sDashCtlHover != -1) {
                sDashHover = -1;
                sDashCtlHover = -1;
                RenderDash();
            }
            return 0;
        case WM_LBUTTONDOWN: {
            const int x = GET_X_LPARAM(l), y = GET_Y_LPARAM(l);
            const int i = DashHitCtl(x, y);
            if (i < 0) return 0;
            switch (sDashCtl[i].kind) {
                case 1:
                    --sCalOffset;
                    RenderDash();
                    break;
                case 2:
                    ++sCalOffset;
                    RenderDash();
                    break;
                case 3:
                    sCalOffset = 0;
                    RenderDash();
                    break;
                case 4:
                    sVolDrag = true;
                    SetCapture(h);
                    DashSetVolumeFromY(y);
                    break;
                case 5:
                    if (sEpVol) {
                        sEpVol->SetMute(sSt.muted ? FALSE : TRUE, nullptr);
                        PollVolume();
                        RenderDash();
                    }
                    break;
            }
            return 0;
        }
        case WM_LBUTTONUP: {
            if (sVolDrag) {
                sVolDrag = false;
                ReleaseCapture();
                PollVolume();
                RenderDash();
                return 0;
            }
            const POINT p = {GET_X_LPARAM(l), GET_Y_LPARAM(l)};
            for (size_t i = 0; i < sDashTabRects.size(); ++i) {
                if (PtInRect(&sDashTabRects[i], p) && (int)i != sDashTab) {
                    sDashTab = (int)i;
                    RenderDash();
                }
            }
            return 0;
        }
        case WM_MOUSEWHEEL: {
            POINT p = {GET_X_LPARAM(l), GET_Y_LPARAM(l)};
            ScreenToClient(h, &p);
            const bool up = GET_WHEEL_DELTA_WPARAM(w) > 0;
            const int i = DashHitCtl(p.x, p.y);
            const int kind = i >= 0 ? sDashCtl[i].kind : 0;
            if (kind == 4 || kind == 5) {
                DashNudgeVolume(up);
            } else if (sDashTab == 0) {
                sCalOffset += up ? -1 : 1;  // wheel up = earlier month
                RenderDash();
            }
            return 0;
        }
        case WM_ERASEBKGND:
            return 1;
    }
    return DefWindowProcW(h, m, w, l);
}

static bool EnsureDashWindow() {
    if (sDash) return true;
    static bool registered = false;
    if (!registered) {
        WNDCLASSEXW wc = {};
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = DashProc;
        wc.hInstance = sInstH;
        wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
        wc.lpszClassName = L"FluidShellDash";
        RegisterClassExW(&wc);
        registered = true;
    }
    sDash = CreateWindowExW(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_NOACTIVATE, L"FluidShellDash",
                            L"Fluid Shell Dashboard", WS_POPUP, 0, 0, 10, 10, nullptr, nullptr, sInstH, nullptr);
    return sDash != nullptr;
}

// The panel is centered at the top of the inner area (just below the top frame).
static void PositionDash() {
    if (!EnsureDashWindow()) return;
    const double dpi = MonitorScale(MonitorFromPoint(POINT{0, 0}, MONITOR_DEFAULTTOPRIMARY));
    RECT inner = sInnerValid ? sInner : RECT{0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
    const int fl = (int)std::lround(cfg.frameRadius * dpi);
    int pw = (int)std::lround(620 * dpi);
    int ph = (int)std::lround(340 * dpi);
    pw = std::min(pw, std::max(200, (int)(inner.right - inner.left) - 2 * fl - 20));
    ph = std::min(ph, std::max(120, (int)(inner.bottom - inner.top) - 20));
    const int sw = pw + 2 * fl;
    const int x = (int)((inner.left + inner.right) / 2) - sw / 2;
    const int y = (int)inner.top;
    if (!DashEnsureSurface(sw, ph)) return;
    SetWindowPos(sDash, HWND_TOPMOST, x, y, sw, ph, SWP_NOACTIVATE | SWP_SHOWWINDOW);
}

static void DashOpen(bool viaEdge) {
    if (!cfg.bar || !cfg.dash || sSuppressed) return;
    if (!sDashWanted) {
        sCalOffset = 0;
        PollVolume();
        PositionDash();
        if (!sDash) return;
        sDashViaEdge = viaEdge;
        sOutsideSince = 0;
        sDashWanted = true;
        SetTimer(sBar, T_DASH, 15, nullptr);
        RenderDash();
    }
}

static void DashClose() {
    if (!sDashWanted) return;
    sDashWanted = false;
    sEdgeArmed = false;  // do not pop up again while the cursor still rests on the hot zone
    SetTimer(sBar, T_DASH, 15, nullptr);
}

static void DashTick() {
    static double last = 0.0;
    const double now = NowSec();
    const double dt = last > 0.0 ? std::min(0.05, now - last) : 0.016;
    last = now;
    bool moving;
    if (sDashWanted) {
        // Same springs as the launcher: only Pop up may overshoot, slides settle without bouncing.
        const double zeta = (g_cfg.anim == AnimStyle::Popup) ? g_cfg.bounceZeta : 1.0;
        moving = SpringTo(sDashK, sDashV, 0.0, zeta, AnimShowSec(), dt, 0.0015, 0.02);
        if (g_cfg.anim != AnimStyle::Popup && sDashK < 0.0) {
            sDashK = 0.0;
            sDashV = 0.0;
        }
    } else {
        SpringTo(sDashK, sDashV, 1.0, 1.0, AnimHideSec(), dt, 0.0015, 0.02);
        moving = sDashK < 0.985;
    }
    RenderDash();
    if (!moving) {
        KillTimer(sBar, T_DASH);
        last = 0.0;
        if (!sDashWanted) {
            sDashK = 1.0;
            sDashV = 0.0;
            if (sDash) ShowWindow(sDash, SW_HIDE);
        }
    }
}

// The hot zone: the top frame strip (+ the window gap) in the middle 40 % of the primary monitor.
static bool InHotZone(const POINT& p) {
    const RECT mon = sInnerValid ? sMonRect : RECT{0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
    const double dpi = MonitorScale(MonitorFromPoint(POINT{0, 0}, MONITOR_DEFAULTTOPRIMARY));
    const int zoneY = cfg.frame ? (int)std::lround((cfg.frameThick + cfg.windowGap) * dpi) : 2;
    const int midX = (mon.left + mon.right) / 2;
    const int halfW = (int)((mon.right - mon.left) * 0.2);
    return p.y >= mon.top && p.y < mon.top + zoneY && p.x >= midX - halfW && p.x <= midX + halfW;
}

// Runs every 60 ms while the dashboard is enabled: hot edge detection and auto close.
static void EdgePoll() {
    if (!cfg.bar || !cfg.dash || !sBar) return;
    POINT p = {};
    if (!GetCursorPos(&p)) return;
    const ULONGLONG nowMs = GetTickCount64();
    const bool inZone = InHotZone(p);
    const bool buttonDown = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) || (GetAsyncKeyState(VK_RBUTTON) & 0x8000);

    if (sDashWanted) {
        if (sVolDrag) return;  // dragging the volume slider: never auto close
        RECT wr = {};
        if (sDash && GetWindowRect(sDash, &wr)) {
            InflateRect(&wr, 12, 12);
            const bool inside = PtInRect(&wr, p) != 0 || inZone;  // resting on the hot zone counts as inside
            if ((!inside && buttonDown) || (GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
                DashClose();
                return;
            }
            if (sDashViaEdge) {
                if (inside) {
                    sOutsideSince = 0;
                } else if (!sOutsideSince) {
                    sOutsideSince = nowMs;
                } else if (nowMs - sOutsideSince > 450) {
                    DashClose();
                    return;
                }
            }
            SYSTEMTIME st;
            GetLocalTime(&st);
            if (sDashTab == 0 && (st.wMinute != sdLastMinute || PollVolume())) RenderDash();  // clock + volume
        }
        return;
    }

    if (!inZone) sEdgeArmed = true;  // re-arm once the cursor has left the zone
    if (!cfg.hotEdge || sSuppressed || g_vis != Vis::Hidden || !sEdgeArmed) {
        sEdgeSince = 0;
        return;
    }
    if (inZone && !buttonDown) {
        if (!sEdgeSince) {
            sEdgeSince = nowMs;
        } else if (nowMs - sEdgeSince >= (ULONGLONG)cfg.hotEdgeMs) {
            sEdgeSince = 0;
            DashOpen(true);
        }
    } else {
        sEdgeSince = 0;
    }
}

static void DashApply() {
    if (!sBar) return;
    UnregisterHotKey(sBar, HK_DASH);
    KillTimer(sBar, T_EDGE);
    if (!cfg.bar || !cfg.dash) {
        sDashWanted = false;
        sDashK = 1.0;
        sDashV = 0.0;
        if (sDash) ShowWindow(sDash, SW_HIDE);
        return;
    }
    static const UINT kMods[3] = {MOD_CONTROL | MOD_ALT, MOD_ALT | MOD_SHIFT, MOD_WIN | MOD_SHIFT};
    const int k = std::clamp(cfg.dashKey, 0, 2);
    RegisterHotKey(sBar, HK_DASH, kMods[k] | MOD_NOREPEAT, 'D');
    SetTimer(sBar, T_EDGE, 60, nullptr);  // also handles auto close of an open dashboard
}

static void DashShutdown() {
    if (sBar) {
        KillTimer(sBar, T_DASH);
        KillTimer(sBar, T_EDGE);
        UnregisterHotKey(sBar, HK_DASH);
    }
    if (sDash) {
        DestroyWindow(sDash);
        sDash = nullptr;
    }
    SafeRelease(sdFmtTab);
    SafeRelease(sdFmtBig);
    SafeRelease(sdFmtSmall);
    SafeRelease(sdBr);
    SafeRelease(sdRt);
    if (sdDib) {
        SelectObject(sdDC, sdOld);
        DeleteObject(sdDib);
        sdDib = nullptr;
    }
    if (sdDC) {
        DeleteDC(sdDC);
        sdDC = nullptr;
    }
}

static void OpenLauncherWithText(const wchar_t* t) {
    if (g_vis == Vis::Hidden || g_vis == Vis::Hiding) ShowLauncher();
    g_text = t;
    g_caret = g_anchor = (int)g_text.size();
    OnTextChanged();
}

static void ActivateOrMinimize(HWND hw) {
    if (!IsWindow(hw)) {
        SetTimer(sBar, T_REFRESH, 30, nullptr);
        return;
    }
    if (IsIconic(hw)) {
        ShowWindow(hw, SW_RESTORE);
        SetForegroundWindow(hw);
    } else if (GetForegroundWindow() == hw) {
        ShowWindow(hw, SW_MINIMIZE);
    } else if (!SetForegroundWindow(hw)) {
        SwitchToThisWindow(hw, TRUE);
    }
    SetTimer(sBar, T_REFRESH, 80, nullptr);
}

static LRESULT CALLBACK BarProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    if (sHookMsg && m == sHookMsg) {  // a window was created, destroyed, activated...
        SetTimer(h, T_REFRESH, 60, nullptr);
        return 0;
    }
    if (sCreatedMsg && m == sCreatedMsg) {  // Explorer restarted: start over
        sHidden = false;
        sOrigState = -1;
        sRegistered = false;
        sShellHooked = false;
        Apply();
        return 0;
    }
    switch (m) {
        case WM_MOUSEACTIVATE:
            return MA_NOACTIVATE;

        case WM_MOUSEMOVE: {
            if (!sTracking) {
                TRACKMOUSEEVENT t = {sizeof(t), TME_LEAVE, h, 0};
                TrackMouseEvent(&t);
                sTracking = true;
            }
            const int i = HitAt(GET_X_LPARAM(l), GET_Y_LPARAM(l));
            if (i != sHover) {
                sHover = i;
                Render();
            }
            return 0;
        }
        case WM_MOUSELEAVE:
            sTracking = false;
            if (sHover != -1) {
                sHover = -1;
                Render();
            }
            return 0;

        case WM_LBUTTONUP: {
            const int i = HitAt(GET_X_LPARAM(l), GET_Y_LPARAM(l));
            if (i < 0) return 0;
            const Hit hit = sHits[i];
            switch (hit.kind) {
                case H_START:
                    SendVk(VK_LWIN, 1);
                    break;
                case H_LAUNCHER:
                    ToggleLauncher();
                    break;
                case H_POWER:
                    OpenLauncherWithText(L">");
                    break;
                case H_WINDOW:
                    ActivateOrMinimize(hit.h);
                    break;
                case H_VOLUME:
                    if (sEpVol) {
                        sEpVol->SetMute(sSt.muted ? FALSE : TRUE, nullptr);
                        PollStatus(false);
                        Render();
                    }
                    break;
                case H_WIFI:
                    ShellExecuteW(nullptr, L"open", L"ms-settings:network-wifi", nullptr, nullptr, SW_SHOWNORMAL);
                    break;
                case H_BATTERY:
                    ShellExecuteW(nullptr, L"open", L"ms-settings:powersleep", nullptr, nullptr, SW_SHOWNORMAL);
                    break;
            }
            return 0;
        }
        case WM_MOUSEWHEEL: {  // wheel over the volume icon = +-5 %
            POINT p = {GET_X_LPARAM(l), GET_Y_LPARAM(l)};
            ScreenToClient(h, &p);
            const int i = HitAt(p.x, p.y);
            if (i >= 0 && sHits[i].kind == H_VOLUME && sEpVol) {
                const bool up = GET_WHEEL_DELTA_WPARAM(w) > 0;
                const float v = std::clamp(sSt.volume + (up ? 0.05f : -0.05f), 0.f, 1.f);
                sEpVol->SetMasterVolumeLevelScalar(v, nullptr);
                if (up && sSt.muted) sEpVol->SetMute(FALSE, nullptr);
                PollStatus(false);
                Render();
            }
            return 0;
        }
        case WM_MBUTTONUP: {
            const int i = HitAt(GET_X_LPARAM(l), GET_Y_LPARAM(l));
            if (i >= 0 && sHits[i].kind == H_WINDOW) {
                PostMessageW(sHits[i].h, WM_CLOSE, 0, 0);
                SetTimer(h, T_REFRESH, 250, nullptr);
            }
            return 0;
        }
        case WM_TIMER:
            if (w == T_REFRESH) {
                KillTimer(h, T_REFRESH);
                RefreshItems();
                Render();
            } else if (w == T_DASH) {
                DashTick();
            } else if (w == T_EDGE) {
                EdgePoll();
            } else if (w == T_POS) {
                KillTimer(h, T_POS);
                PositionBar();
            } else if (w == T_TICK) {
                EvalFullscreen();
                const bool fs = sSuppressed;
                SYSTEMTIME st;
                GetLocalTime(&st);
                const HWND fg = GetForegroundWindow();
                bool redraw = false;
                if (st.wMinute != sLastMinute) {
                    sLastMinute = st.wMinute;
                    redraw = true;
                }
                if (fg != sLastFg) {
                    sLastFg = fg;
                    redraw = true;
                }
                if (cfg.status && PollStatus(sTickCount % 10 == 9)) redraw = true;
                if (++sTickCount % 10 == 0) {  // safety net next to the shell hook
                    RefreshItems();
                    redraw = true;
                }
                if (redraw && !fs) Render();
            }
            return 0;

        case WM_HOTKEY:
            if (w == HK_DASH) {
                if (sDashWanted) {
                    DashClose();
                } else {
                    DashOpen(false);
                }
                return 0;
            }
            if (w == HK_TASKBAR) {  // emergency switch: native taskbar back / hidden again
                if (sHidden) {
                    sRevealed = true;
                    SetTaskbarHidden(false);
                } else {
                    sRevealed = false;
                    if (cfg.bar && cfg.hideTaskbar) SetTaskbarHidden(true);
                }
            }
            return 0;

        case WM_DISPLAYCHANGE:
            SetTimer(h, T_POS, 400, nullptr);
            return 0;

        case WM_APPBAR_CB:
            if (w == ABN_POSCHANGED && GetTickCount64() > sAbnIgnoreUntil) SetTimer(h, T_POS, 150, nullptr);
            if (w == ABN_FULLSCREENAPP) EvalFullscreen();  // only a hint: our own check decides
            return 0;

        case WM_ERASEBKGND:
            return 1;
    }
    return DefWindowProcW(h, m, w, l);
}

// ---------------------------------------------------------------- lifetime
void Init(HINSTANCE inst) {
    sInstH = inst;
    LoadCfg();
    WNDCLASSEXW wc = {};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = BarProc;
    wc.hInstance = inst;
    wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    wc.lpszClassName = L"FluidShellBar";
    RegisterClassExW(&wc);

    sBar = CreateWindowExW(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_NOACTIVATE, wc.lpszClassName,
                           L"Fluid Shell Bar", WS_POPUP, 0, 0, 10, 10, nullptr, nullptr, inst, nullptr);
    if (!sBar) return;
    sHookMsg = RegisterWindowMessageW(L"SHELLHOOK");
    sCreatedMsg = RegisterWindowMessageW(L"TaskbarCreated");
    RegisterHotKey(sBar, HK_TASKBAR, MOD_CONTROL | MOD_ALT | MOD_SHIFT | MOD_NOREPEAT, 'T');
    Apply();
}

bool GetInnerRect(const RECT& mon, RECT* out) {
    if (!sBar || !cfg.bar || !sInnerValid || !out) return false;
    if (mon.left != sMonRect.left || mon.top != sMonRect.top || mon.right != sMonRect.right ||
        mon.bottom != sMonRect.bottom) {
        return false;  // the launcher opened on another monitor
    }
    *out = sInner;
    return true;
}

bool FrameActive() {
    return sBar != nullptr && cfg.bar && cfg.frame;
}

int FrameRadiusDip() {
    return cfg.frameRadius;
}

void OnSettings() {
    if (sBar) Apply();
}

void Shutdown() {
    if (!sBar) return;
    KillTimer(sBar, T_TICK);
    KillTimer(sBar, T_REFRESH);
    KillTimer(sBar, T_POS);
    RemoveEvHook();
    UnhookShell();
    UnregisterHotKey(sBar, HK_TASKBAR);
    SetTaskbarHidden(false);  // always give the taskbar back
    DashShutdown();
    StopNetThread();
    ReleaseVolume();
    TeardownFrame();
    UnregisterBar();
    DestroyWindow(sBar);
    sBar = nullptr;
    SafeRelease(sEllipsis);
    SafeRelease(sFmtV);
    SafeRelease(sFmt);
    SafeRelease(sBr);
    SafeRelease(sRt);
    if (sDib) {
        SelectObject(sDC, sOldBmp);
        DeleteObject(sDib);
        sDib = nullptr;
    }
    if (sDC) {
        DeleteDC(sDC);
        sDC = nullptr;
    }
}

}  // namespace FluidShell

static DWORD WINAPI UiThreadProc(LPVOID) {
    // Per-monitor DPI awareness for this thread (before creating the window)
    {
        typedef HANDLE(WINAPI * SetThreadDpiAwarenessContext_t)(HANDLE);
        HMODULE u = GetModuleHandleW(L"user32.dll");
        auto fn = u ? (SetThreadDpiAwarenessContext_t)GetProcAddress(u, "SetThreadDpiAwarenessContext")
                    : nullptr;
        if (fn) {
            fn((HANDLE)(INT_PTR)-4);  // PER_MONITOR_AWARE_V2
        }
    }

    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    LoadSettings();
    LoadCalcHistory();
    LoadCalcAns();
    LoadPalette();
    if (g_cfg.sounds) Sound::Init();
    Sound::ApplyVolume();

    HINSTANCE hInst = GetModuleHandleW(nullptr);
    WNDCLASSEXW wc = {};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = LauncherWndProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    wc.lpszClassName = L"SpotlightLauncherWindow";
    RegisterClassExW(&wc);

    g_hwnd = CreateWindowExW(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
                             wc.lpszClassName, L"Spotlight Launcher", WS_POPUP, 0, 0, 100, 100,
                             nullptr, nullptr, hInst, nullptr);
    if (!g_hwnd) {
        return 1;
    }
    LiveCreate(hInst);

    D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, __uuidof(ID2D1Factory), nullptr,
                      (void**)&g_d2d);
    DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), (IUnknown**)&g_dw);
    if (g_d2d) {
        g_d2d->CreateStrokeStyle(D2D1::StrokeStyleProperties(D2D1_CAP_STYLE_ROUND,
                                                             D2D1_CAP_STYLE_ROUND,
                                                             D2D1_CAP_STYLE_ROUND,
                                                             D2D1_LINE_JOIN_ROUND),
                                 nullptr, 0, &g_roundStroke);
    }

    RegisterHotkeyOrWarn();
    StartIndex();
    StartWatcher();  // always runs (it is almost free); only used in Automatic mode
    FluidShell::Init(hInst);

    MSG msg;
    while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    FluidShell::Shutdown();
    StopWatcher();
    UnregisterHotKey(g_hwnd, HOTKEY_ID);
    Sound::Shutdown();
    LiveDestroy();
    DestroyWindow(g_hwnd);
    g_hwnd = nullptr;
    ReleaseTarget();
    SafeRelease(g_roundStroke);
    ReleaseFormats();
    SafeRelease(g_dw);
    SafeRelease(g_d2d);
    DestroySurface();
    if (g_memDC) {
        DeleteDC(g_memDC);
        g_memDC = nullptr;
    }
    CoUninitialize();
    return 0;
}

// ===== Tool mod callbacks =====

BOOL WhTool_ModInit() {
    g_uiThread = CreateThread(nullptr, 0, UiThreadProc, nullptr, 0, &g_uiThreadId);
    return g_uiThread != nullptr;
}

void WhTool_ModSettingsChanged() {
    if (g_hwnd) {
        PostMessageW(g_hwnd, WM_APP_SETTINGS, 0, 0);
    }
}

void WhTool_ModUninit() {
    if (g_uiThread) {
        PostThreadMessageW(g_uiThreadId, WM_QUIT, 0, 0);
        WaitForSingleObject(g_uiThread, 3000);
        CloseHandle(g_uiThread);
        g_uiThread = nullptr;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Windhawk tool mod implementation for mods which don't need to inject to other
// processes or hook other functions. Context:
// https://github.com/ramensoftware/windhawk/wiki/Mods-as-tools:-Running-mods-in-a-dedicated-process
//
// The mod will load and run in a dedicated windhawk.exe process.
//
// Paste the code below as part of the mod code, and use these callbacks:
// * WhTool_ModInit
// * WhTool_ModSettingsChanged
// * WhTool_ModUninit
//
// Currently, other callbacks are not supported.

bool g_isToolModProcessLauncher;
HANDLE g_toolModProcessMutex;

void WINAPI EntryPoint_Hook() {
    Wh_Log(L">");
    ExitThread(0);
}

BOOL Wh_ModInit() {
    DWORD sessionId;
    if (ProcessIdToSessionId(GetCurrentProcessId(), &sessionId) &&
        sessionId == 0) {
        return FALSE;
    }

    bool isExcluded = false;
    bool isToolModProcess = false;
    bool isCurrentToolModProcess = false;
    int argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);
    if (!argv) {
        Wh_Log(L"CommandLineToArgvW failed");
        return FALSE;
    }

    for (int i = 1; i < argc; i++) {
        if (wcscmp(argv[i], L"-service") == 0 ||
            wcscmp(argv[i], L"-service-start") == 0 ||
            wcscmp(argv[i], L"-service-stop") == 0) {
            isExcluded = true;
            break;
        }
    }

    for (int i = 1; i < argc - 1; i++) {
        if (wcscmp(argv[i], L"-tool-mod") == 0) {
            isToolModProcess = true;
            if (wcscmp(argv[i + 1], WH_MOD_ID) == 0) {
                isCurrentToolModProcess = true;
            }
            break;
        }
    }

    LocalFree(argv);

    if (isExcluded) {
        return FALSE;
    }

    if (isCurrentToolModProcess) {
        g_toolModProcessMutex =
            CreateMutex(nullptr, TRUE, L"windhawk-tool-mod_" WH_MOD_ID);
        if (!g_toolModProcessMutex) {
            Wh_Log(L"CreateMutex failed");
            ExitProcess(1);
        }

        if (GetLastError() == ERROR_ALREADY_EXISTS) {
            Wh_Log(L"Tool mod already running (%s)", WH_MOD_ID);
            ExitProcess(1);
        }

        if (!WhTool_ModInit()) {
            ExitProcess(1);
        }

        IMAGE_DOS_HEADER* dosHeader =
            (IMAGE_DOS_HEADER*)GetModuleHandle(nullptr);
        IMAGE_NT_HEADERS* ntHeaders =
            (IMAGE_NT_HEADERS*)((BYTE*)dosHeader + dosHeader->e_lfanew);

        DWORD entryPointRVA = ntHeaders->OptionalHeader.AddressOfEntryPoint;
        void* entryPoint = (BYTE*)dosHeader + entryPointRVA;

        Wh_SetFunctionHook(entryPoint, (void*)EntryPoint_Hook, nullptr);
        return TRUE;
    }

    if (isToolModProcess) {
        return FALSE;
    }

    g_isToolModProcessLauncher = true;
    return TRUE;
}

void Wh_ModAfterInit() {
    if (!g_isToolModProcessLauncher) {
        return;
    }

    WCHAR currentProcessPath[MAX_PATH];
    switch (GetModuleFileName(nullptr, currentProcessPath,
                              ARRAYSIZE(currentProcessPath))) {
        case 0:
        case ARRAYSIZE(currentProcessPath):
            Wh_Log(L"GetModuleFileName failed");
            return;
    }

    WCHAR
    commandLine[MAX_PATH + 2 +
                (sizeof(L" -tool-mod \"" WH_MOD_ID "\"") / sizeof(WCHAR)) - 1];
    swprintf_s(commandLine, L"\"%s\" -tool-mod \"%s\"", currentProcessPath,
               WH_MOD_ID);

    HMODULE kernelModule = GetModuleHandle(L"kernelbase.dll");
    if (!kernelModule) {
        kernelModule = GetModuleHandle(L"kernel32.dll");
        if (!kernelModule) {
            Wh_Log(L"No kernelbase.dll/kernel32.dll");
            return;
        }
    }

    using CreateProcessInternalW_t = BOOL(WINAPI*)(
        HANDLE hUserToken, LPCWSTR lpApplicationName, LPWSTR lpCommandLine,
        LPSECURITY_ATTRIBUTES lpProcessAttributes,
        LPSECURITY_ATTRIBUTES lpThreadAttributes, WINBOOL bInheritHandles,
        DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory,
        LPSTARTUPINFOW lpStartupInfo,
        LPPROCESS_INFORMATION lpProcessInformation,
        PHANDLE hRestrictedUserToken);
    CreateProcessInternalW_t pCreateProcessInternalW =
        (CreateProcessInternalW_t)GetProcAddress(kernelModule,
                                                 "CreateProcessInternalW");
    if (!pCreateProcessInternalW) {
        Wh_Log(L"No CreateProcessInternalW");
        return;
    }

    STARTUPINFO si{
        .cb = sizeof(STARTUPINFO),
        .dwFlags = STARTF_FORCEOFFFEEDBACK,
    };
    PROCESS_INFORMATION pi;
    if (!pCreateProcessInternalW(nullptr, currentProcessPath, commandLine,
                                 nullptr, nullptr, FALSE, NORMAL_PRIORITY_CLASS,
                                 nullptr, nullptr, &si, &pi, nullptr)) {
        Wh_Log(L"CreateProcess failed");
        return;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void Wh_ModSettingsChanged() {
    if (g_isToolModProcessLauncher) {
        return;
    }

    WhTool_ModSettingsChanged();
}

void Wh_ModUninit() {
    if (g_isToolModProcessLauncher) {
        return;
    }

    WhTool_ModUninit();
    ExitProcess(0);
}
