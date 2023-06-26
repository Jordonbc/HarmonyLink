<p align="center">
  <img src="Images/HarmonyLinkLogo.png" alt="HarmonyLinkLogo"/>
</p>

Welcome to the server-side application for the HarmonyLink project. This innovative software is developed with the Rust programming language and is aimed at enhancing the handheld gaming experience.

## The Vision and The Reality

The central goal with HarmonyLink is to provide a comprehensive and interactive gaming experience on handheld devices. This client-side application is a crucial part of this vision.

## Key Features

1. **Device Identification**: HarmonyLink equips games with the ability to identify the specific handheld device they are operating on.
2. **Real-Time Metrics**: Games can access real-time data about the handheld device's power usage and docking status through HarmonyLink.
3. **Cross-Platform Compatibility**: HarmonyLink extends its functionality to Windows games running on Proton/Wine.

## Using HarmonyLinkServer

For users who wish to run the precompiled release version of HarmonyLinkServer, please follow the instructions specific to your platform below.

### Windows Users

1. Navigate to the [latest release](https://github.com/Jordonbc/HarmonyLinkServer/releases/latest) on the project's GitHub page.
2. Download the `.zip` archive for Windows.
3. Extract the contents of the `.zip` archive to a directory of your choice.
4. Open a command prompt in the directory where you extracted the files.
5. Run the HarmonyLinkServer executable by typing `./harmony_link_server.exe`.

Please note that you'll need to manually start the program each time you want to use it.

### Steam Deck (Linux) Users

1. Navigate to the [latest release](https://github.com/Jordonbc/HarmonyLinkServer/releases/latest) on the project's GitHub page.
2. Download the `.zip` archive for Linux.
3. Extract the contents of the `.zip` archive to a directory of your choice.

#### Running in Desktop Mode

To use HarmonyLinkServer in Desktop Mode, follow these steps:

1. Open a terminal in the directory where you extracted the files.
2. Run the HarmonyLinkServer executable by typing `./harmony_link_server`.

Please note that you'll need to keep the terminal window open while using HarmonyLinkServer in desktop mode.

#### Optional: Setting Up as a Service for Gamemode

For a seamless experience in gamemode, you have the option to set up HarmonyLinkServer as a service on your Steam Deck. Please be aware that this setup process will require a moderate level of technical knowledge.

## How It Works

HarmonyLink operates using a client-server structure. This server-side application runs on the host side (native Linux or Windows), and games access the metrics via an API.

Developers and modders can easily implement GET and POST requests from the API, integrating system metrics into games. These metrics can be used to adapt the game's quality settings, providing a more customized gaming experience.

## Getting Started
For details on getting started please go to [Getting Started](https://github.com/Jordonbc/HarmonyLinkServer/wiki/Getting-Started)

## HarmonyLink: View

To view the API in action, check out [HarmonyLink: View](https://github.com/Jordonbc/HarmonyLinkView). This sister project provides a comprehensive interface to see what data the API is providing.

## Showcasing HarmonyLink

👇 To help visualize its functionality, we've included a demonstration video that showcases HarmonyLink in action on a Steam Deck in gamemode. [![HarmonyLink in action](https://img.youtube.com/vi/qU3w_fo4nY4/0.jpg)](https://www.youtube.com/watch?v=qU3w_fo4nY4)

## Contributing Guidelines

Please refer to our [Contributing Guidelines](CONTRIBUTING.md) for detailed information on how to contribute to HarmonyLinkServer. It includes instructions for bug reports, feature requests, and pull requests.

We appreciate your interest in improving HarmonyLinkServer and look forward to your contributions!

## Frequently Asked Questions (FAQ)

### Q1: What platforms are supported by HarmonyLink?

A: HarmonyLink supports both native Linux and Windows platforms, and extends its functionality to Windows games running on Proton/Wine.

### Q2: How can I get started with HarmonyLink?

A: You can start by cloning the HarmonyLinkServer repository. Detailed instructions are provided in the [Getting Started](https://github.com/Jordonbc/HarmonyLinkServer#getting-started) section.

### Q3: Can HarmonyLink be used with games developed in different game engines?

A: Yes, HarmonyLink is designed to be engine-agnostic and can be used with games developed in different engines. For Unreal Engine, there is a specific [Unreal Engine Plugin](https://github.com/Jordonbc/HarmonyLinkUE) available.

### Q4: Is HarmonyLink only for game developers, or can players also use it?

A: While game developers will find HarmonyLink particularly useful for optimizing their games for handheld devices, players can also benefit from the enhanced gaming experience that HarmonyLink provides.

### Q5: Does HarmonyLink have any impact on the performance of the games?

A: HarmonyLink is designed to be lightweight and efficient, with minimal impact on game performance. The primary purpose of HarmonyLink is to enhance game performance by allowing games to adapt their settings based on real-time device metrics.

## License

This project is licensed under the GNU General Public License v3.0 or later. Please do not redistribute HarmonyLinkServer. e.g.: Proving an alternative download link or distributing with a game.
