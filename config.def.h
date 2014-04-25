static const char font[]            = "-*-terminus-medium-r-*-*-12-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#5f676a";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#888888";
static const char selbordercolor[]  = "#2e9ef4";
static const char selbgcolor[]      = "#285577";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;
static const unsigned int snap      = 32;
static const Bool showbar           = False;
static const Bool topbar            = True;

static const char *tags[] = { "dev", "web", "com", "hfx", "crp" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            False,         True,        -1 },
	{ NULL,       NULL,       "Scratch",  0,            True,          True,        -1 },
	{ NULL,       NULL,       "Mutt",     1 << 2,       False,         False,       -1 },
	{ NULL,       NULL,       "Terminal", 1,            False,         False,       -1 },
	{ NULL,       NULL,       "Hotfix",   1 << 3,       False,         False,       -1 },
	{ NULL,       NULL,       "Chromium", 1 << 1,       False,         False,       -1 },
	{ NULL,       NULL,       "LDAP",     1 << 4,       False,         False,       -1 },
	{ "ApacheDi", NULL,       NULL,       1 << 4,       False,         False,       -1 },
	{ "Skype",    NULL,       NULL,       1 << 4,       False,         False,       -1 },
	{ NULL,       "keepassx", NULL,       1 << 4,       False,         False,       -1 },
	{ NULL,       "crx_nckg", NULL,       1 << 2,       False,         False,       -1 },
};

static const float mfact      = 0.55;
static const int nmaster      = 1;
static const Bool resizehints = False;

static const Layout layouts[] = {
	{ "TTT",      bstack },
	{ "[]=",      tile },
	{ "><>",      NULL },
	{ "[M]",      monocle },
};

#define MODKEY Mod4Mask
#define TK(EVENT,KEY,TAG) \
	{ EVENT, MODKEY,                         KEY,  view,        {.ui = 1 << TAG} }, \
	{ EVENT, MODKEY|ShiftMask,               KEY,  toggleview,  {.ui = 1 << TAG} }, \
	{ EVENT, MODKEY|ControlMask,             KEY,  tag,         {.ui = 1 << TAG} }, \
	{ EVENT, MODKEY|ControlMask|ShiftMask,   KEY,  toggletag,   {.ui = 1 << TAG} },
#define RK(EVENT,MASK,KEY,ACTION) \
	{ EVENT, MASK,                           KEY,  ACTION,      {.i  = +1 } }, \
	{ EVENT, MASK|ShiftMask,                 KEY,  ACTION,      {.i  = -1 } },

static const char *dmenucmd[]         = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static char        dmenumon[2]        = "0";

static const char *terminal[]         = { "urxvtc", "-title", "Terminal", NULL };
static const char *hotfix[]           = { "urxvtc", "-title", "Hotfix", NULL };
static const char *scratch[]          = { "urxvtc", "-title", "Scratch", "-geometry", "160x40", NULL };
static const char *mutt[]             = { "urxvtc", "-title", "Mutt", "-e", "mutt", NULL };

static const char *passmenu[]         = { "passmenu", "-i", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };

static const char *browser[]          = { "chromium", NULL };
static const char *browser_private[]  = { "chromium", "--incognito", NULL };

static const char *lock[]             = { "vlock-original", "-ans", NULL };

static const char *mpdmenu_library[]  = { "mpdmenu", "-l", "::", "-i", "-l", "3", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *mpdmenu_playlist[] = { "mpdmenu", "-p", "::", "-i", "-l", "3", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };

static const char *toggle_state[]     = { "mpc", "toggle", NULL };
static const char *track_next[]       = { "mpc", "next", NULL };
static const char *track_prev[]       = { "mpc", "prev", NULL };
static const char *volume_down[]      = { "amixer", "-q", "sset", "Master", "5%-", NULL };
static const char *volume_up[]        = { "amixer", "-q", "sset", "Master", "5%+", NULL };

static const char *scrot[]            = { "scrot", "%Y-%m-%dT%H:%M:%S.png", "-z", "-e", "mv $f ~/Screenshots", NULL };
static const char *scrot_focussed[]   = { "scrot", "%Y-%m-%dT%H:%M:%S.png", "-z", "-u", "-e", "mv $f ~/Screenshots", NULL };

static Key keys[] = {
  TK( KeyPress,                       XK_o,            0               )
  TK( KeyPress,                       XK_p,            1               )
  TK( KeyPress,                       XK_bracketleft,  2               )
  TK( KeyPress,                       XK_bracketright, 3               )
  TK( KeyPress,                       XK_k,            4               )
  RK( KeyPress,   MODKEY,             XK_comma,        focusstack      )
  RK( KeyPress,   MODKEY,             XK_period,       focusmon        )
  RK( KeyPress,   MODKEY|ControlMask, XK_period,       tagmon          )
    { KeyPress,   MODKEY,             XK_q,            spawn,          {.v = dmenucmd } },
    { KeyPress,   MODKEY,             XK_w,            spawn,          {.v = passmenu } },
    { KeyPress,   MODKEY,             XK_Return,       spawn,          {.v = terminal } },
    { KeyPress,   MODKEY|ControlMask, XK_Return,       spawn,          {.v = hotfix } },
    { KeyPress,   MODKEY|ShiftMask,   XK_Return,       spawn,          {.v = scratch } },
    { KeyPress,   MODKEY,             XK_m,            spawn,          {.v = mutt } },
    { KeyPress,   MODKEY,             XK_backslash,    spawn,          {.v = browser } },
    { KeyPress,   MODKEY|ControlMask, XK_backslash,    spawn,          {.v = browser_private } },
    { KeyPress,   MODKEY,             XK_slash,        spawn,          {.v = mpdmenu_library } },
    { KeyPress,   MODKEY|ControlMask, XK_slash,        spawn,          {.v = mpdmenu_playlist } },
    { KeyPress,   MODKEY,             XK_Prior,        spawn,          {.v = volume_up } },
    { KeyPress,   MODKEY,             XK_Next,         spawn,          {.v = volume_down } },
    { KeyPress,   MODKEY,             XK_Down,         spawn,          {.v = toggle_state } },
    { KeyPress,   MODKEY,             XK_Right,        spawn,          {.v = track_next } },
    { KeyPress,   MODKEY,             XK_Left,         spawn,          {.v = track_prev } },
    { KeyRelease, MODKEY,             XK_Print,        spawn,          {.v = scrot_focussed } },
    { KeyRelease, False,              XK_Print,        spawn,          {.v = scrot } },
    { KeyPress,   MODKEY,             XK_Delete,       spawn,          {.v = lock } },
    { KeyPress,   MODKEY,             XK_Tab,          zoom,           {0} },
    { KeyPress,   MODKEY,             XK_BackSpace,    killclient,     {0} },
    { KeyPress,   MODKEY|ShiftMask,   XK_space,        togglefloating, {0} },
    { KeyPress,   MODKEY|ShiftMask,   XK_q,            quit,           {0} },
};

static Button buttons[] = {
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = terminal } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

