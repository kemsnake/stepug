<div<?php print $attributes; ?>>
  <header class="l-header" role="banner">
    <div class="l-branding col-xs-5 col-sm-5 col-md-6 col-lg-4">
      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
      <?php endif; ?>

      <?php if ($site_name || $site_slogan): ?>
        <?php if ($site_name): ?>
          <h1 class="site-name">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>
      <?php endif; ?>

      <?php print render($page['branding']); ?>
    </div>

    <div class="l-branding-menu col-xs-7 col-sm-7 col-md-6 col-lg-8">
      <?php print render($page['header']); ?>
    </div>
    <div class="l-navigation col-xs-12 col-sm-12 col-md-12 col-lg-12">


      <?php print render($page['navigation']); ?>
    </div>
  </header>

  <div class="l-main">
    <div class="l-first-sidebar col-xs-4 col-sm-4 col-md-3 col-lg-3 pull-left">
      <?php print render($page['sidebar_first']); ?>
    </div>
    <div class="l-content col-xs-8 col-sm-8 col-md-9 col-lg-9" role="main">
      <?php print render($page['highlighted']); ?>
      <?php print $breadcrumb; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>


    <?php print render($page['sidebar_second']); ?>
  </div>

  <footer class="l-footer" role="contentinfo">
    <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
      <?php print render($page['footer']); ?>
    </div>
  </footer>
</div>
