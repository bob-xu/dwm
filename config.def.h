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
#define TK(KEY,TAG) \
	{ MODKEY,                         KEY,  view,        {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,               KEY,  toggleview,  {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,             KEY,  tag,         {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask,   KEY,  toggletag,   {.ui = 1 << TAG} },
#define RK(MASK,KEY,ACTION) \
	{ MASK,                           KEY,  ACTION,      {.i  = +1 } }, \
	{ MASK|ShiftMask,                 KEY,  ACTION,      {.i  = -1 } },

static const char *dmenu[]            = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };

static const char *terminal[]         = { "urxvtc", "-title", "Terminal", NULL };
static const char *hotfix[]           = { "urxvtc", "-title", "Hotfix", NULL };
static const char *scratch[]          = { "urxvtc", "-title", "Scratch", "-geometry", "160x40", NULL };
static const char *mutt[]             = { "urxvtc", "-title", "Mutt", "-e", "mutt", NULL };

static const char *clipmenu[]         = { "clipmenu", "-i", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };

static const char *browser[]          = { "chromium", NULL };
static const char *browser_private[]  = { "chromium", "--incognito", NULL };

static const char *lock[]             = { "slock", NULL };

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
  TK(                     XK_o,            0          )
  TK(                     XK_p,            1          )
  TK(                     XK_bracketleft,  2          )
  TK(                     XK_bracketright, 3          )
  TK(                     XK_k,            4          )
  RK( MODKEY,             XK_comma,        focusstack )
  RK( MODKEY,             XK_period,       focusmon   )
  RK( MODKEY|ControlMask, XK_period,       tagmon     )
    { MODKEY,             XK_q,            spawn,          {.v = dmenu } },
    { MODKEY,             XK_Return,       spawn,          {.v = terminal } },
    { MODKEY|ControlMask, XK_Return,       spawn,          {.v = hotfix } },
    { MODKEY|ShiftMask,   XK_Return,       spawn,          {.v = scratch } },
    { MODKEY,             XK_m,            spawn,          {.v = mutt } },
    { MODKEY,             XK_backslash,    spawn,          {.v = browser } },
    { MODKEY|ControlMask, XK_backslash,    spawn,          {.v = browser_private } },
    { MODKEY,             XK_slash,        spawn,          {.v = mpdmenu_library } },
    { MODKEY|ControlMask, XK_slash,        spawn,          {.v = mpdmenu_playlist } },
    { MODKEY,             XK_Prior,        spawn,          {.v = volume_up } },
    { MODKEY,             XK_Next,         spawn,          {.v = volume_down } },
    { MODKEY,             XK_Down,         spawn,          {.v = toggle_state } },
    { MODKEY,             XK_Right,        spawn,          {.v = track_next } },
    { MODKEY,             XK_Left,         spawn,          {.v = track_prev } },
    { MODKEY,             XK_Print,        spawn,          {.v = scrot_focussed } },
    { False,              XK_Print,        spawn,          {.v = scrot } },
    { MODKEY,             XK_Delete,       spawn,          {.v = lock } },
    { MODKEY,             XK_Tab,          zoom,           {0} },
    { MODKEY,             XK_BackSpace,    killclient,     {0} },
    { MODKEY|ShiftMask,   XK_space,        togglefloating, {0} },
    { MODKEY|ShiftMask,   XK_q,            quit,           {0} },
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

